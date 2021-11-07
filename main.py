from container import Container
from dataclass import DataClass
import sys

if __name__ == '__main__':
    my_container = Container()
    try:
        if sys.argv[1] == "-f":
            input_file_name = sys.argv[2]
            output_file_name = sys.argv[3]

            # do input
            DataClass.input_from_file(my_container, input_file_name)
            DataClass.output_sorted_data(my_container, output_file_name)
        elif sys.argv[1] == "-n":
            amount = int(sys.argv[2])
            if amount > 10000:
                print("Please, input amount in range: from 1 to 10000")
            else: 
                output_file_name = sys.argv[3]

                # do input
                DataClass.input_random(my_container, amount)
                DataClass.output_sorted_data(my_container, output_file_name)
    except Exception as ex:
        print("There was an error in program")


# See PyCharm help at https://www.jetbrains.com/help/pycharm/
