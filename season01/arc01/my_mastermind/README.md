# Welcome to My Mastermind
***

## Task
The goal of this project was to recreate the classic **Mastermind** game, but with **C programming**.  
The concept is simple: **guess a secret 4-digit code made of unique numbers (0-8) within a limited number of attempts**.  

At first, I thought, "This should be easy!" **I was so wrong.** 😭

## Description
This project turned into a **nightmare**. What was supposed to be **a simple coding challenge** became an **endless cycle of debugging, deleting, rewriting, and fighting with Gandalf**. 

Here’s the **disaster timeline**:

### 🚧 **Step 1: Setting Up the Project**
Everything started smoothly:  
✅ Wrote `main.c`, handling input, comparisons, and validation.  
✅ Created a `Makefile` with all the necessary rules (`all`, `clean`, `fclean`, `re`).  
✅ Set up `README.md` (or so I thought).  

Little did I know, **the real suffering was about to begin.**  

---

### 💀 **Step 2: "Makefile doesn't exist."**  
I wrote a **perfectly fine Makefile**. I could **see it.** I could **touch it.** I could **open it**.  

But Gandalf? **"Makefile doesn't exist."**  
🤨 Excuse me? It's right there. I checked **10 times**.  

**The problem?**  
- The Makefile was inside the `my_mastermind/` folder instead of the project root.  
- Gandalf is picky—he expects it to be in the **root directory**.  

🔧 **Fix:**  
mv my_mastermind/Makefile ./
git add Makefile
git commit -m "Moved Makefile to root"
git push origin dev
And... it finally worked. 😮‍💨
###  **🚨 Step 3: "Forbidden Functions & Syntax Errors."**  
My original implementation used:

scanf() (for input)
getchar() (for clearing the input buffer)
A perfectly reasonable for loop
But guess what?
🚫 FORBIDDEN. 🚫
Gandalf rejected them all.
So, I had to rewrite everything using read(0, &c, 1) to manually collect user input one character at a time.

🔧 Fix:
I replaced scanf() with a custom function:

int read_user_input(char *buffer, int size) {
    int i = 0;
    char c;
    while (i < size - 1) {
        int bytes_read = read(0, &c, 1);
        if (bytes_read <= 0 || c == '\n') {
            break;
        }
        buffer[i] = c;
        i++;
    }
    buffer[i] = '\0';
    return i;
}
🚀 And after that? It finally worked.
## ** 🔥 Step 4 :" The Colon (:) That Almost Made Me Qui!"*
Everything was working except one final error in Gandalf's test:

💥 "expected \"Please enter a valid guess\n\" but got \"Please enter a valid guess:\n\"" 💥

What does this mean? One extra colon (:) at the end of a sentence made Gandalf reject the entire project.

🤡 Me, realizing I lost HOURS of debugging over a single character:

printf("Please enter a valid guess:\n");  ❌ (Wrong)
printf("Please enter a valid guess\n");   ✅ (Correct)
🔧 Fix:
I went through the code and removed every single colon (:) from that line.

🔄 Re-ran Gandalf.
✅ It passed.
But at what cost?
## **"🗑 Step 5: The Great Git Disaster™"**
At some point, I accidentally submitted my project for review too early. 😭
I messaged support, and they told me I had two choices:

Copy my code somewhere safe, delete the project, and start over.
Let them fail it and start over anyway.
I went with option #1, deleted my entire group, and had to recreate everything from scratch.
Thankfully, I always keep my code in my notes (lesson learned from past disasters).

🛠 Fix:

I recreated README.md, Makefile, and main.c.
Restaged and committed everything:

git add .
git commit -m "Recreated Mastermind project from scratch"
git push origin dev
And finally, it was ready.

## Installation
To build the project, simply run:
make
To clean up compiled files:
make clean
To really clean up everything, including compiled files:
make fclean
To rebuild everything from scratch:
make re

## **"What I Learned from This Nightmare"**
Gandalf is brutal. Follow every single rule to the letter, or get rejected.
Never trust a Makefile until Gandalf does.
If your code isn’t working, check for invisible problems (like an extra colon :).
Always keep a backup of your code.
Even the smallest mistakes can cost you hours.




## Usage
Run the game with:  
./my_mastermind
You can provide optional flags:

-c (Custom secret code): Provide a 4-digit number.
-t (Custom number of attempts): Set the number of tries.
Example:
    
./my_mastermind -c 1234 -t 5
This sets the secret code to 1234 and allows 5 attempts to guess it.

```
./my_project argument1 argument2
```

### The Core Team


<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School's Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px' /></span>
