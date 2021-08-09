import pickle, socket, random, sys
from sender import *

DATA_SIZE_FOR_CASE2 = 8
DATA_SIZE_FOR_CASE3 = 6


def generate_random_bits(length, file_name):
    file = open(file_name, "w")
    for i in range(length):
        file.write(str(random.randint(0, 1)))
    file.close()


def inject_error_at_random_position(codewords):
    random_codeword = random.randint(0, len(codewords) - 1)
    random_position = random.randint(0, len(codewords[random_codeword]) - 1)
    toggled_bit = "0" if codewords[random_codeword][random_position] == "1" else "1"
    codewords[random_codeword] = codewords[random_codeword][:random_position] + toggled_bit + codewords[
                                                                                                  random_codeword][
                                                                                              random_position + 1:]
    return codewords


def inject_burst_error(codewords):
    for index in range(len(codewords)):
        no_of_errors = random.randint(3, len(codewords[index])-1)
        for j in range(no_of_errors):
            random_position = random.randint(0, len(codewords[index]) - 1)
            toggled_bit = "0" if codewords[index][random_position] == "1" else "1"
            codewords[index] = codewords[index][:random_position] + toggled_bit + codewords[index][random_position + 1:]

    return codewords


def inject_specific_error(codewords, zeros_pos, ones_pos):
    for i in range(len(zeros_pos)):
        for j in range(len(zeros_pos[i])):
            pos = zeros_pos[i][j]
            codewords[i] = codewords[i][:pos] + '0' + codewords[i][pos + 1:]
    for i in range(len(ones_pos)):
        for j in range(len(ones_pos[i])):
            pos = ones_pos[i][j]
            codewords[i] = codewords[i][:pos] + '1' + codewords[i][pos + 1:]

    return codewords


def case1(data_size, file_name):
    s = socket.socket()
    print("Socket Created Successfully")

    port = 12345
    s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

    s.bind(('', port))
    print("Socket binded to port ", port)

    s.listen(5)

    while True:
        connection, address = s.accept()
        print("\nConnection established with", address)

        SCHEME_NAME = pickle.loads(connection.recv(1024))
        print("\n**Encoding Data-Words using '", SCHEME_NAME, "' Encoding Scheme**")

        if SCHEME_NAME != "CRC":
            sender = Sender(data_size)
            sender.create_codewords(file_name, SCHEME_NAME)
            sender.display_packets(SCHEME_NAME)

            temp = sender.codewords
            sender.codewords = inject_burst_error(sender.codewords)

            data_string = pickle.dumps(sender)

            connection.sendall(data_string)

        else:
            polynomials = open('polynomials.txt').read().splitlines()
            polynomial = random.choice(polynomials)

            sender = Sender(data_size)
            sender.create_codewords(file_name, SCHEME_NAME, polynomial)
            sender.display_packets(SCHEME_NAME)

            sender.codewords = inject_burst_error(sender.codewords)

            data_list = [sender, polynomial]
            data_list = pickle.dumps(data_list)

            connection.sendall(data_list)

        connection.close()


def case2(data_size, file_name):
    s = socket.socket()
    print("Socket Created Successfully")

    port = 12345

    s.bind(('', port))
    print("Socket binded to port ", port)

    s.listen(5)

    zeros_pos = []
    ones_pos = [[5]]

    while True:
        connection, address = s.accept()
        print("Connection established with", address)

        SCHEME_NAME = pickle.loads(connection.recv(1024))
        print("**Encoding Data-Words using ", SCHEME_NAME, " Encoding Scheme**")

        if SCHEME_NAME == "CHECKSUM":
            sender = Sender(data_size)
            sender.create_codewords(file_name, SCHEME_NAME)
            sender.display_packets(SCHEME_NAME)

            sender.codewords = inject_specific_error(sender.codewords, zeros_pos, ones_pos)

            data_string = pickle.dumps(sender)
            connection.sendall(data_string)

        elif SCHEME_NAME == "CRC":
            polynomial = "1000"

            sender = Sender(data_size)
            sender.create_codewords(file_name, SCHEME_NAME, polynomial)
            sender.display_packets(SCHEME_NAME)

            sender.codewords = inject_specific_error(sender.codewords, zeros_pos, ones_pos)

            data_list = [sender, polynomial]
            data_list = pickle.dumps(data_list)

            connection.sendall(data_list)
        else:
            error_msg = "Invalid Client Connected!\n"
            print(error_msg)
            connection.sendall(pickle.dumps(error_msg))

        connection.close()


def case3(data_size, file_name):
    s = socket.socket()
    print("Socket Created Successfully")

    port = 12345

    s.bind(('', port))
    print("Socket binded to port ", port)

    s.listen(5)

    zeros_pos = []
    ones_pos = [[5]]

    while True:
        connection, address = s.accept()
        print("Connection established with", address)

        SCHEME_NAME = pickle.loads(connection.recv(1024))
        print("**Encoding Data-Words using ", SCHEME_NAME, " Encoding Scheme**")

        if SCHEME_NAME == "VRC":
            sender = Sender(data_size)
            sender.create_codewords(file_name, SCHEME_NAME)
            sender.display_packets(SCHEME_NAME)

            sender.codewords = inject_specific_error(sender.codewords, zeros_pos, ones_pos)

            data_string = pickle.dumps(sender)
            connection.sendall(data_string)

        elif SCHEME_NAME == "CRC":
            polynomial = "100"

            sender = Sender(data_size)
            sender.create_codewords(file_name, SCHEME_NAME, polynomial)
            sender.display_packets(SCHEME_NAME)

            sender.codewords = inject_specific_error(sender.codewords, zeros_pos, ones_pos)

            data_list = [sender, polynomial]
            data_list = pickle.dumps(data_list)

            connection.sendall(data_list)
        else:
            error_msg = "Invalid Client Connected!\n"
            print(error_msg)
            connection.sendall(pickle.dumps(error_msg))

        connection.close()


if __name__ == '__main__':
    if len(sys.argv) < 2:
        print("Missing File Name. Aborting Program..")
        exit(1)
    print("----------------------MENU----------------------")
    print("1. Error is detected by all four schemes.")
    print("2. Error is detected by checksum but not by CRC.")
    print("3. Error is detected by VRC but not by CRC.")
    print("4. Exit.")
    case = int(input("Enter Your Choice: "))
    if case == 1:
        size = int(input("Enter length of data-word(multiples of 8 preferable): "))
        number = int(input("Enter number: "))
        generate_random_bits(size * number, sys.argv[1])
        case1(size, sys.argv[1])
    elif case == 2:
        case2(DATA_SIZE_FOR_CASE2, sys.argv[1])
    elif case == 3:
        case3(DATA_SIZE_FOR_CASE3, sys.argv[1])
    elif case == 4:
        exit(1)
    else:
        print("Invalid Choice!")
