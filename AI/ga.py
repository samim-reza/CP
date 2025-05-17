countries = ["CANADA", "FRANCE", "BRAZIL", "JAPANL", "RUSSA", "SWEDEN",
             "GREECE", "MEXICO"]

def fitness(name):
    vowles = "AEIOU"
    return sum(1 for c in name if c in vowles)

fitness_values = {country: fitness(country) for country in countries}
selected = sorted(fitness_values.items(), key=lambda x: x[1],
                 reverse=True)[:4]
selected_countries = [item[0] for item in selected]
print("Selected Parents: ", selected_countries)

def find_2nd_vowel_index(name):
    vowels = "AEIOU"
    count = 0
    for idx, c in enumerate(name):
        if c in vowels:
            count += 1
            if count == 2:
                return idx
    return -1

p1, p2 = selected_countries[0], selected_countries[1]
idx1 = find_2nd_vowel_index(p1)
offspring1 = p1[:idx1]+p2[idx1:]

p3, p4 = selected_countries[2], selected_countries[3]
idx2 = find_2nd_vowel_index(p3)
offspring2 = p3[:idx2]+p4[idx2:]

print("Offspring before mutatuion:")
print("Offspring 1:" , offspring1)
print("Offspring 2:" , offspring2)

def mutate(name):
    return name.replace('A','X').replace('E', 'X')

final_offspring1 = mutate(offspring1)
final_offspring2 = mutate(offspring2)

print("Offspring after mutation:")
print("Offspring 1:" , final_offspring1)
print("Offspring 2:" , final_offspring2)