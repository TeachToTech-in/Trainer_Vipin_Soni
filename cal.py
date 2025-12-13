import tkinter as tk

# Function to update expression in the text entry box
def press(num):
    global expression
    expression += str(num)
    equation.set(expression)

# Function to evaluate final expression
def equalpress():
    try:
        global expression
        total = str(eval(expression))   # eval safely calculates math expressions
        equation.set(total)
        expression = total
    except:
        equation.set(" error ")
        expression = ""

# Function to clear the input
def clear():
    global expression
    expression = ""
    equation.set("")

# Main GUI window
window = tk.Tk()
window.title("Calculator")
window.geometry("320x400")

expression = ""
equation = tk.StringVar()

# Entry field
entry = tk.Entry(window, textvariable=equation, font=('Arial', 20), justify="right")
entry.grid(columnspan=4, ipadx=8, ipady=8, pady=10)

# Buttons
buttons = [
    ('7',1,0), ('8',1,1), ('9',1,2), ('/',1,3),
    ('4',2,0), ('5',2,1), ('6',2,2), ('*',2,3),
    ('1',3,0), ('2',3,1), ('3',3,2), ('-',3,3),
    ('0',4,0), ('.',4,1), ('=',4,2), ('+',4,3),
]

for (text, row, col) in buttons:
    if text == "=":
        b = tk.Button(window, text=text, width=10, height=3, bg="lightgreen", command=equalpress)
    else:
        b = tk.Button(window, text=text, width=10, height=3, command=lambda t=text: press(t))
    b.grid(row=row, column=col, padx=5, pady=5)

# Clear button
clear_btn = tk.Button(window, text="Clear", width=44, height=2, bg="lightcoral", command=clear)
clear_btn.grid(row=5, column=0, columnspan=4, padx=5, pady=10)

window.mainloop()
