
# Tkinter Python Module for GUI
from tkinter import Tk, Frame, Scrollbar, Label, END, Entry, Text, VERTICAL, Button, messagebox, ttk
import socket
import threading
from ttkthemes import *


class GUI:
    client_socket = None
    last_received_message = None

    def __init__(self, master):
        self.root = master
        root.configure(background='#DAE7FF')
        self.chat_transcript_area = None
        self.name_widget = None
        self.enter_text_widget = None
        self.join_button = None
        self.initialize_socket()
        self.initialize_gui()
        self.listen_for_incoming_messages_in_a_thread()

    def initialize_socket(self):
        self.client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        remote_ip = '127.0.0.1'
        remote_port = 10319
        self.client_socket.connect((remote_ip, remote_port))

    def initialize_gui(self):
        self.root.title("Chat")
        self.display_name_section()
        self.display_chat_box()
        self.display_chat_entry_box()

    def listen_for_incoming_messages_in_a_thread(self):
        thread = threading.Thread(
            target=self.receive_message_from_server, args=(self.client_socket,))
        thread.start()

    def receive_message_from_server(self, so):
        while True:
            buffer = so.recv(256)
            if not buffer:
                break
            message = buffer.decode('utf-8')

            if "joined" in message:
                user = message.split(":")[1]
                message = user + " has joined"
                self.chat_transcript_area.insert('end', message + '\n')
                self.chat_transcript_area.yview(END)
            else:
                self.chat_transcript_area.insert('end', message + '\n')
                self.chat_transcript_area.yview(END)

        so.close()

    def display_name_section(self):
        frame = Frame(bg="#DAE7FF")
        Label(frame, text='Enter your name:', font=("Nunito", 12),
              bg="#DAE7FF").pack(side='left', padx=10)
        self.name_widget = Entry(
            frame, width=34, borderwidth=0, bd=0, font=("Nunito light", 12))
        self.name_widget.pack(side='left', anchor='e',
                              ipady=5, ipadx=3, pady=10)
        self.join_button = Button(frame, text="Join", font=("Nunito", 12), width=8, pady="0", padx="0", bd=0,
                                  bg="#3F3E91", fg="#FFFFFF", activebackground="#28285D", activeforeground="#FFFFFF", command=self.on_join)
        self.join_button.pack(side='left', padx=(0, 15))
        frame.pack(side='top')

    def display_chat_box(self):
        frame = Frame(bg="#DAE7FF")
        Label(frame, text='Chat Box:', font=("Nunito", 12), bg="#DAE7FF").pack(
            side='top', anchor='w', padx=10, pady=10)
        self.chat_transcript_area = Text(
            frame, width=53, height=10, font=("Nunito", 12), bd=0)
        style = ttk.Style()
        style.theme_use('arc')
        style.configure("Vertical.TScrollbar",
                        background="#DAE7FF", arrowcolor="#3F3E91", bd=0)
        scrollbar = ttk.Scrollbar(
            frame, command=self.chat_transcript_area.yview, orient=VERTICAL)
        self.chat_transcript_area.config(yscrollcommand=scrollbar.set)
        self.chat_transcript_area.bind('<KeyPress>', lambda e: 'break')
        self.chat_transcript_area.pack(side='left', padx=10)
        scrollbar.pack(side='right', fill='y')
        frame.pack(side='top')

    def display_chat_entry_box(self):
        frame = Frame(bg="#DAE7FF")
        Label(frame, text='Enter message:', font=("Nunito", 12), bg="#DAE7FF").pack(
            side='top', anchor='w', padx=10, pady=(20, 0))
        self.enter_text_widget = Text(
            frame, width=55, height=3, font=("Nunito light", 12), bd=0)
        self.enter_text_widget.pack(side='left', pady=(8, 20), padx=10)
        self.enter_text_widget.bind('<Return>', self.on_enter_key_pressed)
        frame.pack(side='top')

    def on_join(self):
        if len(self.name_widget.get()) == 0:
            messagebox.showerror(
                "Enter your name", "Enter your name to send a message")
            return
        self.join_button.config(state="disabled", bg="#828A99")
        self.name_widget.config(state='disabled')
        self.client_socket.send(
            ("joined:" + self.name_widget.get()).encode('utf-8'))

    def on_enter_key_pressed(self, event):
        if len(self.name_widget.get()) == 0:
            messagebox.showerror(
                "Enter your name", "Enter your name to send a message")
            return
        self.send_chat()
        self.clear_text()

    def clear_text(self):
        self.enter_text_widget.delete(1.0, 'end')

    def send_chat(self):
        senders_name = self.name_widget.get().strip() + ": "
        data = self.enter_text_widget.get(1.0, 'end').strip()
        message = (senders_name + data).encode('utf-8')
        self.chat_transcript_area.insert('end', message.decode('utf-8') + '\n')
        self.chat_transcript_area.yview(END)
        self.client_socket.send(message)
        self.enter_text_widget.delete(1.0, 'end')
        return 'break'

    def on_close_window(self):
        if messagebox.askokcancel("Quit", "Do you want to quit?"):
            self.root.destroy()
            self.client_socket.close()
            exit(0)


#the mail function
if __name__ == '__main__':
    root = ThemedTk(theme="arc")
    gui = GUI(root)
    root.protocol("WM_DELETE_WINDOW", gui.on_close_window)
    root.mainloop()
