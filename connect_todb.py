#db connector
import sqlite3 as sq
con = sq.connect("database.db")
cursor = con.cursor() 