def chatbot():
    name = input("Bot: Hello! what's your name? ")
    msg = input(f"Bot: {name} Say hi, tell me if you're sad, or just type anything: ").lower()

    if "hi" in msg or "hello" in msg:
        fav = input("Bot: Nice! I know you like anime, so Who’s your favorite anime character? ")
        print(f"Bot: Legendary pick, {name}: he's perfect {fav}")
    elif "sad" in msg:
        fav = input("Bot: Don't be sad, {name}. ..hm tell me Which anime character cheers you up? ")
        print(f"Bot: {fav} is pure comfort, I agree.")
    else:
        print(f"Bot: Cool vibe, {name}! Keep loving anime ")

    bye = input("Bot: Type 'bye' to finish or press Enter to chat more: ").lower()
    if bye == "bye":
        print(f"Bot: Bye {name}!")
    else:
        chatbot()
chatbot()