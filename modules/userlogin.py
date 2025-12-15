#user login and sign up module
from connect_todb import con,cursor
def create_user_table():
    con.execute("""
create table if not exists user
                (email text primary key,
                password text)""")
    con.commit()
def check_exists(e,p):
    cursor.execute("""
select * from user where email=? AND password=?""",(e,p))
    row = cursor.fetchone()
    if row:
        return True
    else: 
        return False
#login function
def login():
    print("Welcome back!!")
    email=input("Enter the email_id")
    password=input("Enter your password")
    
    if(check_exists(email,password)):
        print("Login sucessfully!!")
        return email
    else:
        print("Please sign up or password or email might be wrong")
        return False
def sign_in():
    validate=" "
    print("HEllo there new user!!")
    email = input("Please enter the valid email")
    password = input("Set your password")
    validate = input("Confirm your password")
    while(password != validate):
        validate = input("Opps did'nt match enter")
        
    cursor.execute("""
insert into user
                   values(?,?)""",(email,password))
    print("Account created sucessfully!!")
    con.commit()
    # login()

