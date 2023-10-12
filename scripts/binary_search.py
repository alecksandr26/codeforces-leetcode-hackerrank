import random

# Function to generate inputs and outputs
def generate_test_case():
    # Generate a random array of numbers (sorted)
    N = random.randint(1, 100000)
    arr = [random.randint(-10**9, 10**9) for _ in range(N)]
    arr.sort()

    # Generate random queries
    Q = random.randint(1, 1000)
    queries = [random.choice(arr) for _ in range(Q)]

    # Calculate the expected outputs
    outputs = []
    for query in queries:
        if query in arr:
            position = arr.index(query)
            outputs.append(position)
        else:
            outputs.append(-1)

    return N, Q, arr, queries, outputs

# Generate and print a test case
N, Q, arr, queries, outputs = generate_test_case()

print(f"{N} {Q}")
print(" ".join(map(str, arr)))
for query in queries:
    print(query)

for output in outputs:
    print(output)
