test = {
  'name': 'Does it work?',
  'points': 0,
  'suites': [
    {
      'cases': [
        {
          'answer': 'No problem, this is a beautiful iterator!',
          'choices': [
            'No problem, this is a beautiful iterator!',
            'Uh oh, this is missing __next__.',
            'This "iterator" doesn\'t even define __iter__.'
          ],
          'hidden': False,
          'locked': False,
          'question': r"""
          Does IteratorA work?
          
          class IteratorA:
             def __init__(self):
                 self.start = 10
          
             def __next__(self):
                 if self.start > 100:
                     raise StopIteration
                 self.start += 20
                 return self.start
          
             def __iter__(self):
                 return self
          """
        },
        {
          'answer': 'Uh oh, this is missing __next__.',
          'choices': [
            'No problem, this is a beautiful iterator!',
            'Uh oh, this is missing __next__.',
            'This "iterator" doesn\'t even define __iter__.'
          ],
          'hidden': False,
          'locked': False,
          'question': r"""
          Does IteratorB work?
          
          class IteratorB:
              def __init__(self):
                  self.start = 5
          
              def __iter__(self):
                  return self
          """
        },
        {
          'answer': 'This "iterator" doesn\'t even define __iter__.',
          'choices': [
            'No problem, this is a beautiful iterator!',
            'Uh oh, this is missing __next__.',
            'This "iterator" doesn\'t even define __iter__.'
          ],
          'hidden': False,
          'locked': False,
          'question': r"""
          Does IteratorC work?
          
          class IteratorC:
              def __init__(self):
                  self.start = 5
          
              def __next__(self):
                  if self.start == 10:
                      raise StopIteration
                  self.start += 1
                  return self.start
          """
        },
        {
          'answer': 'No problem, this is a beautiful iterator!',
          'choices': [
            'No problem, this is a beautiful iterator!',
            'Uh oh, this is missing __next__.',
            'This "iterator" doesn\'t even define __iter__.'
          ],
          'hidden': False,
          'locked': False,
          'question': r"""
          Does IteratorD work?
          
          class IteratorD:
              def __init__(self):
                  self.start = 1
          
              def __next__(self):
                  self.start += 1
                  return self.start
          
              def __iter__(self):
                  return self
          """
        }
      ],
      'scored': False,
      'type': 'concept'
    }
  ]
}
