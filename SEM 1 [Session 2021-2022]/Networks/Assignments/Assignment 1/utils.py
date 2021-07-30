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


# print(binary_division("111101000", "110"))
