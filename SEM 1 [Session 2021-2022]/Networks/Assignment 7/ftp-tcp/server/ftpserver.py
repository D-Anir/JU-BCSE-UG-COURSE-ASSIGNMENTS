import socket
from pathlib import Path

HOST = '127.0.0.2'  # Standard loopback interface address (localhost)
PORT = 65300        # Port to listen on (non-privileged ports are > 1023)

print("FTP Server started!!")
while True:
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1) # to avoid 'Address already in use error'
    
    s.bind((HOST, PORT))
    print("Listening for a connection on its own port....\n")
    s.listen()

    conn, addr = s.accept()
    name = conn.recv(1024).decode()
    filename = conn.recv(1024).decode()
    print("Client ", name, " with address " , addr , " is requesting file: ", filename)

    # checking file existence
    filename = Path(filename)
    if filename.is_file():
        file = open(filename, 'r')
        data = file.read()
        conn.send(bytes(data, "utf-8")) 
        print("Data sent!\n")
        
    else:
        error = "File does not exists. Terminating Request..."
        print(error, "\n")
        conn.send(bytes("-1", "utf-8"))
    
    s.close()
    print("FTP Server still running!")
