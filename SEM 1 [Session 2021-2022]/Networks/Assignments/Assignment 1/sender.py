from utils import *


class Sender:
    def __init__(self, size):
        self.codewords = []
        self.size = size
        self.redundant_parity_byte = ""
        self.checksum = ""

    def create_codewords(self, file_name, scheme, polynomial=""):
        file = open(file_name, "r")
        packet = file.readline()
        file.close()

        if scheme == "LRC":
            self.codeword_util(packet)
            self.lrc_parity_generator()

        elif scheme == "VRC":
            self.codeword_util(packet)
            self.vrc_parity_generator()

        elif scheme == "CHECKSUM":
            self.codeword_util(packet)
            sum_of_fragments = self.calculate_sum()
            for index in range(len(sum_of_fragments)):
                if sum_of_fragments[index] == '0':
                    self.checksum += '1'
                else:
                    self.checksum += '0'

        elif scheme == "CRC":
            self.crc_codeword_util(packet, polynomial)

    def display_packets(self, scheme):
        data_words = []
        for x in self.codewords:
            data_words.append(x[:self.size])
        print("Data-Words:")
        print(data_words)
        print("Code-Words Sent by Sender:")
        print(self.codewords)
        if scheme == "LRC":
            print(self.redundant_parity_byte, " - parity")
        elif scheme == "CHECKSUM":
            print("CheckSum: ", self.checksum)
        print("\n")

    def codeword_util(self, packet):
        temp_word = ""
        for index in range(len(packet)):
            if index != 0 and index % self.size == 0:
                self.codewords.append(temp_word)
                temp_word = ""
            temp_word += packet[index]
        self.codewords.append(temp_word)

    def crc_codeword_util(self, packet, polynomial):
        temp_word = ""
        data_size = self.size
        for index in range(len(packet)):
            if index != 0 and index % data_size == 0:
                temp_word += '0' * (len(polynomial) - 1)
                remainder = binary_division(temp_word, polynomial)
                remainder = remainder[len(remainder) - len(polynomial) - 1:]
                temp_word = temp_word[:data_size]
                temp_word += remainder
                self.codewords.append(temp_word)
                temp_word = ""

            temp_word += packet[index]

        temp_word += '0' * (len(polynomial) - 1)
        remainder = binary_division(temp_word, polynomial)
        remainder = remainder[len(remainder) - len(polynomial) - 1:]
        temp_word = temp_word[:data_size]
        temp_word += remainder
        self.codewords.append(temp_word)

    def vrc_parity_generator(self):
        for i in range(len(self.codewords)):
            one_count = 0
            for j in range(len(self.codewords[i])):
                if self.codewords[i][j] == '1':
                    one_count += 1
            if one_count % 2 == 1:
                self.codewords[i] += '1'
            else:
                self.codewords[i] += '0'

    def lrc_parity_generator(self):
        for index in range(self.size):
            one_count = 0
            for j in range(len(self.codewords)):
                if self.codewords[j][index] == "1":
                    one_count += 1
            if one_count % 2 == 1:
                self.redundant_parity_byte += "1"
            else:
                self.redundant_parity_byte += "0"

    def calculate_sum(self):
        answer = self.codewords[0]
        for index in range(1, len(self.codewords)):
            answer = binary_addition(answer, self.codewords[index])
            while len(answer) > self.size:
                part1 = answer[:len(answer) - self.size]
                part2 = answer[len(answer) - self.size:]
                answer = binary_addition(part1, part2)
        return answer
