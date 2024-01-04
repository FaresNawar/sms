import pyperclip
import random

def random_float(min, max):
    """Generate a random float number between min and max"""
    return round(random.uniform(min,max), 2)


classes = ['A']

names = ['Ilham', 'Ilyes', 'Khalifa', 'Ashraqat', 'Basira', 'Abdur Rahim', 'Shahira', 'Nura', 'Jalila', 'Nail', 'Nida', 'Mohamed', 'Hani', 'Sameer', 'Abdur Rashid', 'Rizwana', 'Asma', 'Sadi', 'Haidar', 'Hanifa', 'Abd al-Latif', 'Gamal', 'Ruya', 'Aziz', 'Abdelaziz', 'Rahim', 'Arij', 'Rasul', 'Maqsud', 'Shariah', 'Ramiz', 'Fariha', 'Zakiah', 'Ebrahim', 'Ayyub', 'Abd ar-Rashid', 'Yunus', 'Noora', 'Asif', 'Najib', 'Nagib', 'Safia', 'Oualid', 'Ruba', 'Humaira', 'Youcef', 'Shareef', 'Malika', 'Jamal', 'Adnan', 'Najm', 'Amjad', 'Nagi', 'Zaid', 'Waheeda', 'Hania', 'Asadullah', 'Shaimaa', 'Abdul Hamid', 'Salima', 'Wedad', 'Ismaeel', 'Murtada', 'Aamina', 'Naseer', 'Hanifa', 'Ismail', 'Saaida', 'Safiya', 'Qasim', 'Abdul Aziz', 'Mahfuz', 'Fadi', 'Umran', 'Lina', 'Abu', 'Zakariyya', 'Kareem', 'Iitidal', 'Ala ad-Din', 'Rashad', 'Zain', 'Omran', 'Fazl', 'Shaban', 'Samira', 'Raja', 'Bahij', 'Maruf', 'Imaan', 'Malak', 'Fatin', 'Hadiyya', 'Safi', 'Aamina', 'Fadila', 'Salha', 'Haneef', 'Hisham', 'Zahia', 'Qamar', 'Wadud', 'Abla', 'Abdul Rahman', 'Farrah', 'Faraj', 'Hooda', 'Abd al-Latif', 'Djamila', 'Rasul', 'Rana', 'Majdi', 'Fareeha', 'Toufik', 'Bassam', 'Basma', 'Shahd', 'Shukri', 'Zaid', 'Bassem', 'Hassan', 'Ali', 'Fares', 'Marwan', 'Youssef', 'Mohamed', 'Michael', 'Abdel Aziz', 'Omar', 'Wael', 'Karim', 'Islam', 'Abdallah', 'Ahmed', 'Adham']

result = ''
existing_ids = [0]
existing_names = []
student_count = int(input("Student count: "))

for i in range(student_count):
    new_student = [
        random.choice(classes),
        random.randint(1, student_count),
        (random.choice(names) + " " + random.choice(names)),
        random.randint(14, 19),
        random_float(80, 99),
        random_float(80, 99)
    ]

    while new_student[1] in existing_ids:
        new_student[1] = random.randint(1, student_count)
    existing_ids.append(new_student[1])

    while new_student[2] in existing_names:
        new_student[2] = (random.choice(names) + " " + random.choice(names))
    existing_names.append(new_student[2])

    for item in new_student:
        result += str(item)
        result += '\n'
    result += '\n\n'

pyperclip.copy(result)
