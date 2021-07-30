from utils import *


class Receiver:
    def __init__(self, sender):
        self.codewords = sender.codewords
        self.size = sender.size
        self.actual_redundant_parity_byte = sender.redundant_parity_byte
        self.received_redundant_parity_byte = ""
        self.actual_checksum = sender.checksum
        self.checksum = ""
        self.added_checksum = ""
        self.complement_sum = ""

    def check_error(self, scheme, polynomial=""):
        if scheme == "VRC":
            for i in range(len(self.codewords)):
                one_count = 0
                for j in range(len(self.codewords[i])):
                    if self.codewords[i][j] == '1':
                        one_count += 1
                if one_count % 2 == 1:
                    print("Parity is ODD. ERROR DETECTED.")
                else:
                    print("Parity is EVEN. NO ERROR DETECTED.")

        elif scheme == "LRC":
            is_error = False
            for index in range(self.size):
                one_count = 0
                for j in range(len(self.codewords)):
                    if self.codewords[j][index] == "1":
                        one_count += 1

                if one_count % 2 == 1:
                    redundant_bit = "1"
                else:
                    redundant_bit = "0"
                self.received_redundant_parity_byte += redundant_bit
                if redundant_bit != self.actual_redundant_parity_byte[index]:
                    is_error = True
            if is_error:
                print("Parity not matched. ERROR DETECTED.")
            else:
                print("Parity matched. NO ERROR DETECTED.")

        elif scheme == "CHECKSUM":
            self.checksum = self.calculate_sum()
            answer = binary_addition(self.checksum, self.actual_checksum)
            # answer = self.checksum
            while len(answer) > self.size:
                part1 = answer[:len(answer) - self.size]
                part2 = answer[len(answer) - self.size:]
                answer = binary_addition(part1, part2)
            self.added_checksum = answer

            is_error = False
            for char in answer:
                if char == '0':
                    self.complement_sum += '1'
                    is_error = True
                else:
                    self.complement_sum += '0'
            if is_error:
                print("Complement is non-zero. ERROR DETECTED.")
            else:
                print("Complement is zero. NO ERROR DETECTED.")

        elif scheme == "CRC":
            for index in range(len(self.codewords)):
                remainder = binary_division(self.codewords[index], polynomial)
                is_error = False
                for j in range(len(remainder)):
                    if remainder[j] == '1':
                        is_error = True
                print("Remainder:", remainder, end=' ')
                if is_error:
                    print("ERROR DETECTED")
                else:
                    print("NO ERROR DETECTED")

    def display_packets(self, scheme):
        print("Code-Words Received by Receiver:")
        print(self.codewords)
        data_words = []
        for x in self.codewords:
            data_words.append(x[:self.size])
        print("Data-Words after Extracting:")
        print(data_words)

        if scheme == "LRC":
            print(self.received_redundant_parity_byte, " - parity")
        elif scheme == "CHECKSUM":
            print("CheckSum: ", self.checksum)
        print("\n")

    def calculate_sum(self):
        answer = self.codewords[0]
        for index in range(1, len(self.codewords)):
            answer = binary_addition(answer, self.codewords[index])
            while len(answer) > self.size:
                part1 = answer[:len(answer) - self.size]
                part2 = answer[len(answer) - self.size:]
                answer = binary_addition(part1, part2)
        return answer
