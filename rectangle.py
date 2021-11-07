from shape import Shape


class Rectangle(Shape):
    def __init__(self, color, line):
        Shape.__init__(self, color)
        self.is_valid = True
        self.input(line)

    def input(self, line):
        Shape.set(self, line, 2)

    def output(self, file):
        out_str = (self.color + " Rectangle: " +
                                " hightLeftX = " + str(self.nodes[0].X) +
                                " hightLeftY = " + str(self.nodes[0].Y) +
                                " lowLeftX = " + str(self.nodes[0].X) +
                                " lowRightX = " + str(self.nodes[1].Y) +
                                " Perimeter = " + str(self.get_perimeter()) + "\n")
        file.write(out_str)

        if not self.is_valid:
            out_str = "This input was invalid\n"
            file.write(out_str)

    def get_perimeter(self):
        horizontal = self.nodes[0].X - self.nodes[1].X
        vertical = self.nodes[0].Y - self.nodes[1].Y
        if horizontal < 0 or vertical < 0:
            self.is_valid = False
        return 2 * (abs(horizontal) + abs(vertical))
