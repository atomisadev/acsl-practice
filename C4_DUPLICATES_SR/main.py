import sys


class Node:
  def __init__(self, val):
    self.val = val
    self.left = None
    self.right = None
    self.count = 1


def insert(root, val):
  if not root:
    return Node(val)
  if val < root.val:
    root.left = insert(root.left, val)
  elif val > root.val:
    root.right = insert(root.right, val)
  else:
    root.count += 1
  return root


def count_single_child(root):
  if not root:
    return 0
  if (root.left and not root.right) or (root.right and not root.left):
    return root.count
  return count_single_child(root.left) + count_single_child(root.right)


for line in sys.stdin:
  root = None
  line = line.strip().upper()
  for c in line:
    if c.isalpha():
      root = insert(root, c)

  print(count_single_child(root))