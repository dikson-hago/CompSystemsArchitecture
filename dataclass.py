from helper import Helper
from random import randint


class DataClass:
    @staticmethod
    def __get_nodes_amount_by_shape_type(shape_type):
        if shape_type == 1:
            return 4
        elif shape_type == 2:
            return 6
        else:
            return 3

    @staticmethod
    def input_from_file(new_container, file_name):
        file = open(file_name, "r")
        lines = file.readlines()
        shape_type = 0
        shape_color = 0
        counter = 0
        for line in lines:
            data = Helper.get_list_of_nums(line)
            if counter % 2 == 0:
                shape_type = data[0]
                shape_color = data[1]
            else:
                new_container.set_shape(data, shape_type, shape_color)
            counter += 1
        file.close()

    @staticmethod
    def input_random(new_container, shapes_amount):
        for i in range(0, shapes_amount):
            shape_color = randint(1, 7)
            shape_type = randint(1, 3)
            size = DataClass.__get_nodes_amount_by_shape_type(shape_type)
            data = Helper.get_random_list(size)
            new_container.set_shape(data, shape_type, shape_color)

    @staticmethod
    def output_sorted_data(new_container, file_name):
        file = open(file_name, 'w')
        new_container.output(file)
        file.close()

