import socket

Host = '127.0.0.2'  # The server's hostname or IP address
FTPport = 65300        # The port used by the server

name = input("Enter name of the client: ")

while True:
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    choice = int(input("\n1. Retrieve file.\n2. Quit.\nEnter Your Choice: "))
    if choice == 1:
        s.connect((Host, FTPport))
        s.send(bytes(name, "utf-8"))
        filename = input("Enter filename to be searched: ")
        s.send(bytes(filename, "utf-8"))
        data = s.recv(1024).decode()

        # if filename is invalid
        if data == "-1":
            print("File does not exists. Terminating Request..")
            continue
        else:
            print("New File Created in Client with the contents: \n" + data + "\n")
            file = open(filename, "w")
            file.write(data)

        s.close()
    
    elif choice == 2:
        print("Client Disconnected..")
        break
    else:   
        print("Invalid Choice. Try Again.")