#main module(app.py)
from modules.userlogin import create_user_table,sign_in,login
create_user_table()
#main function
print("Welcome to the study world")
option = input("1.login 2.sign in :")
match (option):
    case "login":
        login()
    case "sign in":
        sign_in()
