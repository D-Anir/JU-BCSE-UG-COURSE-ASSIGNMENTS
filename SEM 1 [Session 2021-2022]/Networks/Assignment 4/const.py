'''module for assiging values to variables that remain constant throughout the flow during execution'''

import random

def Average(lst):
    return sum(lst) / len(lst)

total_sender_number       = 64
total_receiver_number     = 64
default_data_packet_size  = 1

sender_sleep_time         = 0.1

input_file_path           = "./textfiles/input/"
output_file_path          = "./textfiles/output/"
