from utils import lowercase, key_of_max
import string
from collections import OrderedDict    # Variant of dict that you might want to learn about

#
# WordSet class
#
class WordSet:
    """Set of unique words, all in lower case and of positive length.

    >>> WordSet("one two, Two. tHree").words()
    ['one', 'three', 'two']
    >>> WordSet(["one","two","Two", ""]).words()
    ['one', 'two']
    >>> 'two' in WordSet(["one","two","Two"])
    True
    """
    def __init__(self, text):
        """Form a WordSet from a string of words or collection of words.
        """
        # BEGIN Question 2
        self.word_set = []

        chrlst = [chr(i) for i in range(97, 123)]

        if type(text) == str:
            lst = text.split()
            for i in lst:
                y = ''
                lower = i.lower()
                for k in range(len(i)):
                    if lower[k] in chrlst:
                        y += lower[k]

                if y not in self.word_set and y != '':
                    self.word_set += [y]

        else:
            for k in text:
                lst = k.split()
                for i in lst:
                    y = ''
                    lower = i.lower()
                    for k in range(len(i)):
                        if lower[k] in chrlst:
                            y += lower[k]

                    if y not in self.word_set and y != '':
                        self.word_set += [y]
        # END Question 2

    def words(self):
        """Return sorted list of words in WordSet.

        >>> WordSet("Hi. Hey you. How, the heck, are you?").words()
        ['are', 'heck', 'hey', 'hi', 'how', 'the', 'you']
        """
        # BEGIN Question 2
        return sorted(self.word_set)
        # END Question 2

    def __contains__(self, word):
        # BEGIN Question 2
        return word in self.word_set
        # END Question 2


#
# Dictionary class
#
class Dictionary(WordSet):
    """Construct a dictionary from all the words in a text file.
    Subclass of WordSet with a file based initializer.

    >>> from wordset import Dictionary
    >>> Dictionary('assets/lincoln.txt').words()[55]
    'government'
    """
    def __init__(self, filename):
        with open(filename) as fp:
            text = fp.read()
            WordSet.__init__(self, text)

#
# WordMunch class
#
class WordMunch(WordSet):
    """Perform analytics on a set of unique words.

    Subclass of WordSet that provides analytics on the words.

    >>> w = WordMunch("one two, Two. tHree")
    >>> w.words()
    ['one', 'three', 'two']
    >>> w.frequency()['o']
    2
    >>> key_of_max(w.frequency())
    'e'
    """
    def filter(self, ffun):
        """Filter set to include only those that satisfy the filter function predicate."""
        # BEGIN
        return [i for i in self.words() if ffun(i)]
        # END

    def frequency(self):
        """Return an ordered dictionary of the frequency of each letter in the word set."""
        # BEGIN
        letters = string.ascii_lowercase
        dic = {}

        for alphab in letters:
            count = 0
            for word in self.words():
                for i in range(len(word)):
                    if word[i] == alphab:
                        count += 1
            dic[alphab] = count

        return dic

        # END
