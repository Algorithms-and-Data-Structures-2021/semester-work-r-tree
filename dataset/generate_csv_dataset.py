import argparse
import random


def parse_args():
    parser = argparse.ArgumentParser(description="Random numbers generator")

    parser.add_argument('output',
                        type=str,
                        help='output CSV file, e.g. data/output.csv')

    parser.add_argument('--samples',
                        type=int,
                        default=100,
                        help='number of samples to generate (default: {})'.format(100))

    return parser.parse_args()


if __name__ == '__main__':
    args = parse_args()

    # валидация аргументов
    if args.samples < 0:
        raise ValueError('Number of samples must be greater than 0.')

        # запись данных в файл
    with open(args.output, 'w') as file:
        for i in range(args.samples):
            x_coord = random.randint(0, 100)
            y_coord = random.randint(0, 100)

            file.write(str(x_coord) + "," + str(y_coord) + "\n")
