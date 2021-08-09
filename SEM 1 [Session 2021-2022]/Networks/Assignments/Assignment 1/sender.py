from utils import *


class Sender:
    def __init__(self, size):
        self.codewords = []
        self.size = size
        self.redundant_parity_byte = ""
        self.checksums = []
        self.polynomial = ""

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
            for i in range(len(self.codewords)):
                divisions = make_divisions(self.codewords[i])
                sum_of_divisions = calculate_sum(divisions)
                checksum = ""
                for j in range(len(sum_of_divisions)):
                    if sum_of_divisions[j] == '0':
                        checksum += '1'
                    else:
                        checksum += '0'
                self.checksums.append(checksum)

        elif scheme == "CRC":
            self.polynomial = polynomial
            self.crc_codeword_util(packet, polynomial)

    def display_packets(self, scheme):
        data_words = []
        for x in self.codewords:
            data_words.append(x[:self.size])
        print("Data-Words:")
        print(data_words)
        print("Code-Words Sent by Sender:")
        print(self.codewords)
        if scheme == "CRC":
            print("Polynomial Used: ", self.polynomial)
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
            if index > 0 and index % data_size == 0:
                temp_word += '0' * (len(polynomial) - 1)
                remainder = binary_division(temp_word, polynomial)
                remainder = remainder[len(remainder) - (len(polynomial) - 1):]
                temp_word = temp_word[:data_size]
                temp_word += remainder
                self.codewords.append(temp_word)
                temp_word = ""

            temp_word += packet[index]

        temp_word += '0' * (len(polynomial) - 1)
        remainder = binary_division(temp_word, polynomial)
        remainder = remainder[len(remainder) - (len(polynomial) - 1):]
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
        LENGTH_OF_DIVISIONS = self.size // 4
        for i in range(len(self.codewords)):
            count = [0] * LENGTH_OF_DIVISIONS
            for k in range(0, LENGTH_OF_DIVISIONS):
                for j in range(k, len(self.codewords[i]), LENGTH_OF_DIVISIONS):
                    if self.codewords[i][j] == '1':
                        count[k] += 1

            parity = ""
            for k in range(0, LENGTH_OF_DIVISIONS):
                if count[k] % 2 == 1:
                    parity += "1"
                else:
                    parity += "0"
            self.codewords[i] += parity
