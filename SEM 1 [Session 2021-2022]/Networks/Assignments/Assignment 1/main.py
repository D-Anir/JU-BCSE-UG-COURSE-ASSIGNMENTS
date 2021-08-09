from sender import *
from receiver import *
import random
import sys


def generate_random_bits(length, file_name):
    file = open(file_name, "w")
    for i in range(length):
        file.write(str(random.randint(0, 1)))
    file.close()


def inject_error_at_random_position(codewords):
    # for i in range(len(codewords)):
    random_codeword = random.randint(0, len(codewords) - 1)
    random_position = random.randint(0, len(codewords[random_codeword]) - 1)
    toggled_bit = "0" if codewords[random_codeword][random_position] == "1" else "1"
    codewords[random_codeword] = codewords[random_codeword][:random_position] + toggled_bit + codewords[
                                                                                                  random_codeword][
                                                                                              random_position + 1:]


def case1(data_size, file_name):
    # vrc
    # s = Sender(data_size)
    # s.create_codewords(file_name, "VRC")
    # s.display_packets("VRC")
    #
    # inject_error_at_random_position(s.codewords)
    #
    # r = Receiver(s)
    # r.check_error("VRC")
    # r.display_packets("VRC")
    #
    # # lrc
    # s = Sender(data_size)
    # s.create_codewords(file_name, "LRC")
    # s.display_packets("LRC")
    #
    # inject_error_at_random_position(s.codewords)
    #
    # r = Receiver(s)
    # r.check_error("LRC")
    # r.display_packets("LRC")

    # checksum
    # s = Sender(data_size)
    # s.create_codewords(file_name, "CHECKSUM")
    # s.display_packets("CHECKSUM")
    #
    # inject_error_at_random_position(s.codewords)
    #
    # r = Receiver(s)
    # # for word in range(len(r.codewords)):
    # r.check_error("CHECKSUM")
    # print()
    # r.display_packets("CHECKSUM")

    # CRC
    polynomial = input("Enter Generator Polynomial: ")
    s = Sender(data_size)
    s.create_codewords(file_name, "CRC", polynomial)
    s.display_packets("CRC")

    inject_error_at_random_position(s.codewords)

    r = Receiver(s)
    # for word in range(len(r.codewords)):
    r.check_error("CRC", polynomial)
    r.display_packets("CHECKSUM")


if __name__ == '__main__':
    size = int(input("Enter length of data-word: "))
    generate_random_bits(size * 5, sys.argv[1])
    case1(size, sys.argv[1])
