# Engineering Renaissance RPG
## You are tasked with making your own video game!
This is due for presentation--yes I said presentation--on Nov 22.

Your program MUST include the following:
1) RPG (role playing game) elements, meaning give your game some sort of coherent reason for existing (e.g. a story, if you so choose)
2) Input (e.g. if I press up arrow on my keyboard, the program better know it was an up arrow)
3) Output (e.g. my character better move up if I pressed the up arrow)
4) Conditions (e.g. logic, meaning if-statements)
5) Loops (e.g. if the player doesn't choose to quit, keep playing the game)
6) Functions (e.g. if the player decides to move up against the border of your world map, they better not be able to go past it)
7) A world map (e.g. vectors and cout statements)
8) Some sort of interactive element beyond walking (e.g. combat, trading, persuasion, sneaking, or anything you can think of really)

**Note: This program does NOT have to be super complex, long, or in-depth. We do ask that a good amount of effort is put into it, however, and that it works with minimal and non-game breaking bugs by the time Nov 22nd rolls around.**

## Getting Started
### Generating your SSH key
To begin make sure you have git installed on your system. Once you do, please do the following to link your git to your github.
1. Type in the following command into the terminal *(make sure you replace the email with the email you used to create your github account with)*:

```ssh-keygen -t ed25519 -C "your_email@example.com"```

2. It should ask you to enter where you want to store your key. Please store it in:

   ```/home/YOU/.ssh/github_key```

   *Note: "YOU" is the name of your account name on your PC*

3. Then it should ask you to enter a passphrase. Enter a secure passphrase because you will have to remember it later.
4. Finally, it will generate some random keyart image and save your key.

### Adding your SSH key to your SSH-agent
1. Start your ssh-agent in the background using the following command:

```eval "$(ssh-agent -s)"```

2. Then add your key:

```ssh-add ~/.ssh/github_key```

### Adding your SSH key to Github
1. Copy your SSH key to your clipboard. You can see the contents of it by running:

```cat ~/.ssh/github_key.pub```

3. In the upper-right corner of any page on GitHub, click your profile photo, then click Settings.
4. In the "Access" section of the sidebar, click SSH and GPG keys.
5. Click New SSH key or Add SSH key.
6. In the "Title" field, add a descriptive label for the new key. For example, if you're using a personal laptop, you might call this key "Personal laptop".
7. Select the type of key, either authentication or signing. For more information about commit signing, see "About commit signature verification."
8. In the "Key" field, paste your public key.
9. Click Add SSH key.
10. If prompted, confirm access to your account on GitHub. For more information, see "Sudo mode."

### Cloning your Git Repository
1. Once you are done with all of that clone the repository by clicking the "Code" button on the top of the repository.
2. Then, make sure it says "SSH" instead of "HTTPS"
3. Copy the long string below it, it should start with "git@github.com:"
4. Finally, clone the repository,

```git clone {the thing you copied}```
