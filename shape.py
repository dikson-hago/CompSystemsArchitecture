from node import Node
from helper import Helper


class Shape:
    def __init__(self, color_num):
        self.nodes = []
        self.color = Helper.get_color(color_num)

    def set(self, data, size):
        for i in range(0, size):
            x = data[2 * i]
            y = data[2 * i + 1]
            self.nodes.append(Node(x, y))
