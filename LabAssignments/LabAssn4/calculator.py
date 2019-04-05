f = open("quiz_grades.txt", "r")
grades_list=[];
for i in range(10):
  line = f.readline()
  grades = []
  g = line.split();
  for grade in g:
    grades.append(int(grade))
  grades_list.append(grades)

print(grades_list);



