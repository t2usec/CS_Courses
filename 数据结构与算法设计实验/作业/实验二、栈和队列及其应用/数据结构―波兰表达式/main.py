def evaluate_prefix(expression):
    stack = []
    operators = set(["+", "-", "*", "/"])

    for char in reversed(expression.split()):
        if char in operators:
            operand1 = stack.pop()
            operand2 = stack.pop()
            if char == "+":
                result = operand1 + operand2
            elif char == "-":
                result = operand1 - operand2
            elif char == "*":
                result = operand1 * operand2
            elif char == "/":
                result = operand1 / operand2
            stack.append(result)
        else:
            stack.append(float(char))
    return stack[0]

while True:
    try:
        prefix_expression = input()
        result = evaluate_prefix(prefix_expression)
        print(f"{result:.6f}")
    except:
        break