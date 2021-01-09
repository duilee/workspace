"""Board class for Wheel of Fortune game."""

class Board:
    """Board for Wheel of Fortune with attributes board and guessed.
    Attributes:
       board - list of correct characters or "_" in the secret word
       guessed - list of characters guessed so far

    >>> from secret import SecretWord
    >>> b = Board(SecretWord("bookkeeper"))
    >>> len(b)
    10
    >>> b.guess('o')
    2
    >>> b
    < _ o o _ _ _ _ _ _ _ : o >
    >>> b.done()
    False
    >>> b.guess('k')
    2
    >>> b
    < _ o o k k _ _ _ _ _ : o,k >
    >>> b.guess('j')
    0
    >>> b
    < _ o o k k _ _ _ _ _ : o,k,j >
    >>> b.word()
    ['_', 'o', 'o', 'k', 'k', '_', '_', '_', '_', '_']
    >>> b.guesses()
    ['o', 'k', 'j']
    """
    def __init__(self, secret):
        """Create an initial board with no guesses and a secret."""
        # BEGIN
        self.board = ["_" for i in range(len(secret))]
        self.guesslist = []
        self.secret = secret
        # END

    def __repr__(self):
        return '< ' + " ".join(self.word()) + " : " + ",".join(self.guesses()) + ' >'

    def __len__(self):
        return self.word_len()

    def word_len(self):
        """Return the length of the secret word."""
        # BEGIN
        return len(self.secret)
        # END

    def word(self):
        """Return the current state of guessing the word as a lsit of characters.
        Unguessed positions are represented by '_'
        Guessed positions hold the character.
        """
        # BEGIN
        return self.board
        # END

    def guesses(self):
        """Return a list of the characters guessed so far."""
        # BEGIN
        return self.guesslist
        # END

    def hits(self):
        """Return a list of characters correctly guessed."""
        # BEGIN
        return [i for i in self.guess if i in self.board]
        # END

    def misses(self):
        """Return a list of characters incorrectly guessed."""
        # BEGIN
        return [i for i in self.guess if i not in self.board]
        # END

    def guess(self, char):
        """Update the board to reflect the guess of char.
        Return the number of indices in the secret word where char occurs.
        If char does not appear in the word, this will be 0.
        """
        # BEGIN
        if char not in self.guesslist:
            self.guesslist += [char]

        charindex = self.secret.match(char)

        if len(charindex) == 0:
            return 0
        else:
            for i in charindex:
                self.board[i] = char
            return len(charindex)
            


        # END

    def done(self):
        """Determine if the game is done."""
        # BEGIN
        if '_' in self.board:
            return False
        else:
            return True
        # END

    max_miss = 11
    # def miss_man(missed):
    #     missed = min(missed, Board.max_miss)
    #     return "assets/man{0}.txt".format(missed)

    def display(self):
        missed = len(self.misses())
        # path = Board.miss_man(missed)
        # with open(path) as fp:
        #     symbol = fp.read()
        # print(symbol)
        print(self.word())
        print("Guessed chars: ", self.guesses())
