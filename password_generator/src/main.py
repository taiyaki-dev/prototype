import password_generator

print(">> Random Password Generator <<")

num_digit :int = int(input("Digit? >> "))
abc_upper_check :str = input("ABC?(y or n) >> ")
abc_lower_check :str = input("abc?(y or n) >> ")

print(password_generator.generatePassword(num_digit, abc_upper_check, abc_lower_check))
