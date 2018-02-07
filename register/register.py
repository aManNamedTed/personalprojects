import datetime

#Finds Tax Rate in the string from registerDetails
def findTax(string):
    if(string[0] == 'T' and string[1] == 'a' and string[2] == 'x'
    and string[3] == ':'):
        taxRate = float(string[4:])
    else:
        print("tax string is either missing or modified")
    return taxRate

#Finds Receipt Number in the string from registerDetails
def findReceiptNumber(string):
    if(string[0] == 'R' and string[1] == 'e' and string[2] == 'c'
    and string[3] == 'e' and string[4] == 'i' and string[5] == 'p'
    and string[6] == 't' and string[7] == ' '):
        receiptNumber = str(string[16:])
    else:
        print("Receipt Number is either missing or modified. Aborting...")
        receiptNumber = -1

    return str(receiptNumber)

#Print Receipt Header
def printHeader():
    now = datetime.datetime.now()
    registerDetails = open("registerDetails", "r")
    stringifiedRegisterDetails = registerDetails.readlines()

    receiptNumber = findReceiptNumber(stringifiedRegisterDetails[0])
    taxRate = findTax(stringifiedRegisterDetails[1])
    cashierName = findCashier()

    print("=======================================")
    print("The Store")
    print("123 Avenue")
    print("City, State 12345")
    print("555.555.5555")
    print("Where Bargains Live!")
    print()
    print("Order: {}".format(receiptNumber))
    print("Cashier: {}".format(cashierName))

    registerDetails.close()
    return

#Calculate Tax
def calcTax(subTotal, taxRate):
    return (subTotal + (subTotal * taxRate))

#A Sale
def sale():
    printHeader()
    return

#B Return Item
def returnItem():
    return

#C Close Register
def closeRegister():
    return

#D Duplicate Receipt
def duplicateReceipt():
    return

#E No Sale
def noSale():
    print("Register opens")
    input("Press enter to close the register...")
    return

#F Employee Sale
def employeeSale():
    return

#G Employee Return
def employeeReturn():
    return

#H Loans
def loans():
    return

#I Price Check
def priceCheck():
    return

#J Inquiries
def inquiries():
    return

#K Opening Balance
def openingBalance():
    return

#L Closing Counts
def closingCounts():
    return

#M Gift Receipt
def giftReceipt():
    return

# Verify Login
def verifyLogin(cashierNumber, cashierPassword)
    return

# Cashier Sign-in
def login():
    cashierNumber = input("Cashier Number: ")
    cashierPassword = input("Cashier Password: ")


    return

# Transaction Selection
def menu():
    loop = False

    print("David's Universal POS")
    print("""
        #A: Sale
        #B: Return
        #C: Close Register
        #D: Duplicate Receipt
        #C: Post Void
        E: No Sale
        #F: Employee Sale
        #G: Employee Return
        #H: Loans
        #I: Price Check
        #J: Inquiries
        #K: Opening Balance
        #L: Closing Counts
        #M: Gift Receipt
    """)
    ans=input("Selection: ")
    if ((ans == "A") or (ans == "a")):
        sale()
        loop = True
    elif ((ans == "B") or (ans == "b")):
        returnItem()
        loop = True
    elif ((ans == "C") or (ans == "c")):
        closeRegister()
        loop = True
    elif ((ans == "D") or (ans == "d")):
        duplicateReceipt()
        loop = True
    elif ((ans == "E") or (ans == "e")):
        noSale()
        loop = True
    elif ((ans == "F") or (ans == "f")):
        employeeSale()
        loop = True
    elif ((ans == "G") or (ans == "g")):
        employeeReturn()
        loop = True
    elif ((ans == "H") or (ans == "h")):
        loans()
        loop = True
    elif ((ans == "I") or (ans == "i")):
        priceCheck()
        loop = True
    elif ((ans == "J") or (ans == "j")):
        inquiries()
        loop = True
    elif ((ans == "K") or (ans == "k")):
        openingBalance()
        loop = True
    elif ((ans == "L") or (ans == "l")):
        closingCounts()
        loop = True
    elif ((ans == "M") or (ans == "m")):
        giftReceipt()
        loop = True
    else:
        input("Wrong option selection. Selection: ")
        loop = False

    return loop

loop = True
while loop:
    loop = menu()
    loop = False #run once only; remove after finish
