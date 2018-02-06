import datetime

#Print Receipt Header
def printHeader():
    now = datetime.datetime.now()
    file = open("registerDetails", "r")
    print("=======================================")
    print("The Store")
    print("123 Avenue")
    print("City, State 12345")
    print("555.555.5555")
    print("Where Bargains Live!")
    print()
    return

#Calculate Tax
def calcTax(subtotal):
    registerDetails = open("registerDetails", "r")
    print(registerDetails.readlines())
    return (subtotal + (subtotal * tax_rate))
#A
def sale():
    return

#B
def returnItem():
    return

#C
def closeRegister():
    return

#D
def duplicateReceipt():
    return

#E
def noSale():
    print("Register opens")
    input("Press enter to close the register...")
    return

#F
def employeeSale():
    return

#G
def employeeReturn():
    return

#H
def loans():
    return

#I
def priceCheck():
    return

#J
def inquiries():
    return

#K
def openingBalance:
    return

#L
def closingCounts():
    return

#M
def giftReceipt():
    return

def menu():
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
        input("")
    elif ((ans == "B") or (ans == "b")):
        returnItem()
        input("")
    elif ((ans == "C") or (ans == "c")):
        closeRegister()
        input("")
    elif ((ans == "D") or (ans == "d")):
        duplicateReceipt()
        input("")
    elif ((ans == "E") or (ans == "e")):
        noSale()
        input("")
    elif ((ans == "F") or (ans == "f")):
        employeeSale()
        input("")
    elif ((ans == "G") or (ans == "g")):
        employeeReturn()
        input("")
    elif ((ans == "H") or (ans == "h")):
        loans()
        input("")
    elif ((ans == "I") or (ans == "i")):
        priceCheck()
        input("")
    elif ((ans == "J") or (ans == "j")):
        inquiries()
        input("")
    elif ((ans == "K") or (ans == "k")):
        openingBalance()
        input("")
    elif ((ans == "L") or (ans == "l")):
        closingCounts()
        input("")
    elif ((ans == "M") or (ans == "m")):
        giftReceipt()
        input("")
    else:
        input("Wrong option selection. Enter a valid option...")

    return True

loop = True
while loop:
    loop = menu()
    loop = False #run once only; remove after finish
