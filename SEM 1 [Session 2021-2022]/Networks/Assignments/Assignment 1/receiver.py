from utils import *


class Receiver:
    def __init__(self, sender):
        self.codewords = sender.codewords
        self.size = sender.size
        self.actual_redundant_parity_byte = sender.redundant_parity_byte
        self.received_redundant_parity_byte = ""
        self.actual_checksums = sender.checksums
        self.checksums = []
        self.polynomial = sender.polynomial
        self.accuracy = 0

    def check_error(self, scheme, polynomial=""):
        if scheme == "VRC":
            for i in range(len(self.codewords)):
                one_count = 0
                for j in range(len(self.codewords[i])):
                    if self.codewords[i][j] == '1':
                        one_count += 1
                if one_count % 2 == 1:
                    print("Parity is ODD. ERROR DETECTED.")
                    self.accuracy += 1
                else:
                    print("Parity is EVEN. NO ERROR DETECTED.")

        elif scheme == "LRC":
            is_error = False
            LENGTH_OF_DIVISIONS = self.size // 4
            for i in range(len(self.codewords)):
                count = [0] * LENGTH_OF_DIVISIONS
                parity_received = self.codewords[i][len(self.codewords[i]) - LENGTH_OF_DIVISIONS:]
                for k in range(0, LENGTH_OF_DIVISIONS):
                    for j in range(k, len(self.codewords[i][:len(self.codewords[i]) - LENGTH_OF_DIVISIONS]),
                                   LENGTH_OF_DIVISIONS):
                        if self.codewords[i][j] == '1':
                            count[k] += 1

                parity_calculated = ""
                for k in range(0, LENGTH_OF_DIVISIONS):
                    if count[k] % 2 == 1:
                        parity_calculated += "1"
                    else:
                        parity_calculated += "0"

                if parity_received[0] != parity_calculated[0]:
                    is_error = True

                if is_error:
                    print("Parity not matched. ERROR DETECTED.")
                    self.accuracy += 1
                else:
                    print("Parity matched. NO ERROR DETECTED.")

        elif scheme == "CHECKSUM":
            for i in range(len(self.codewords)):
                divisions = make_divisions(self.codewords[i])
                sum_of_divisions = calculate_sum(divisions)
                sum_of_divisions = binary_addition(sum_of_divisions, self.actual_checksums[i])
                checksum = ''
                for j in sum_of_divisions:
                    if j == '1':
                        checksum += '0'
                    else:
                        checksum += '1'

                is_error = False
                if int(checksum, 2) != 0:
                    is_error = True
                if is_error:
                    print("Complement is non-zero. ERROR DETECTED.")
                    self.accuracy += 1
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
                    self.accuracy += 1
                else:
                    print("NO ERROR DETECTED")
        print()

    def display_packets(self, scheme):
        print("Code-Words Received by Receiver:")
        # print(self.codewords)
        if scheme == "CRC":
            print("Polynomial Used: ", self.polynomial)
        print("Accuracy: ", round((self.accuracy / len(self.codewords)) * 100, 5), "%")
        print("\n")
