LENGTH_OF_DIVISIONS = 0


def binary_addition(binary1, binary2):
    result = ""
    i = len(binary1) - 1
    j = len(binary2) - 1
    carry = 0
    while i >= 0 or j >= 0 or carry == 1:
        if i >= 0:
            carry += int(binary1[i])
        if j >= 0:
            carry += int(binary2[j])
        result = str(carry % 2) + result
        carry = carry // 2
        i = i - 1
        j = j - 1
    return result


def binary_xor(binary1, binary2):
    answer = ""
    for index in range(1, len(binary2)):
        if binary1[index] == binary2[index]:
            answer += '0'
        else:
            answer += '1'

    return answer


def binary_division(dividend, divisor):
    length_of_xor = len(divisor)
    remainder = dividend[:length_of_xor]
    while len(dividend) > length_of_xor:
        if remainder[0] == '1':
            remainder = binary_xor(divisor, remainder) + dividend[length_of_xor]
        else:
            remainder = binary_xor('0' * length_of_xor, remainder) + dividend[length_of_xor]
        length_of_xor += 1

    if remainder[0] == '1':
        remainder = binary_xor(divisor, remainder)
    else:
        remainder = binary_xor('0' * length_of_xor, remainder)

    return remainder


def make_divisions(codeword):
    divisions = []
    temp_word = ""
    global LENGTH_OF_DIVISIONS
    LENGTH_OF_DIVISIONS = len(codeword) // 4
    for i in range(len(codeword)):
        if i > 0 and i % LENGTH_OF_DIVISIONS == 0:
            divisions.append(temp_word)
            temp_word = ""
        temp_word += codeword[i]
    divisions.append(temp_word)

    return divisions


def calculate_sum(divisions):
    answer = divisions[0]
    # print(LENGTH_OF_DIVISIONS)
    for index in range(1, len(divisions)):
        answer = binary_addition(answer, divisions[index])
        while len(answer) > LENGTH_OF_DIVISIONS:
            part1 = answer[:len(answer) - LENGTH_OF_DIVISIONS]
            part2 = answer[len(answer) - LENGTH_OF_DIVISIONS:]
            answer = binary_addition(part1, part2)
    return answer
