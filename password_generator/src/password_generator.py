import random
import string

def checkDigitSize(num: int) -> bool:
    if(num <= 0):
        print("Please input a number above 1")
        return False
    else:
        return True

def checkInputChar(inputcmd: str) -> bool:
    if (inputcmd == 'y') or (inputcmd == 'n'):
        return True
    else:
        print("Inputed apart from y or n")
        return False

def selectOnOff(inputcmd: str) -> bool:
    if inputcmd == "y":
        return True
    else :
        return False

def generatePassword(digit :int, abc_upper_check :str, abc_lower_check :str) -> str:

    # 入力された桁数が1以上であるかチェックする
    if checkDigitSize(digit) == False:
        quit()
    
    # 入力された文字がy/nであるかチェックする
    if checkInputChar(abc_upper_check) == True:
        abc_upper = selectOnOff(abc_upper_check)
    else:
        quit()

    # 入力された文字がy/nであるかチェックする
    if checkInputChar(abc_lower_check) == True:
        abc_lower = selectOnOff(abc_lower_check)
    else:
        quit()

    password :str = ""
    count = digit

    # パスワード生成で使用する文字
    ascii_digits = string.digits
    ascii_lowercase = string.ascii_lowercase
    ascii_uppercase = string.ascii_uppercase

    while count > 0:
        str_type :int = random.randint(0,2)
        if str_type == 0:
            password += random.choice(ascii_digits)
            count = count-1
        elif (str_type == 1) and (abc_upper == True):
            password += random.choice(ascii_uppercase)
            count = count-1
        elif (str_type == 2) and (abc_lower == True):
            password += random.choice(ascii_lowercase)
            count = count-1

    return password
