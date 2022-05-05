#include <iostream>
#include <vector>

class Person{

	protected:
		std::string firstName;
		std::string lastName;
		int id;

	public:
		Person(std::string firstName, std::string lastName, int identification){

			this->firstName = firstName;
			this->lastName = lastName;
			this->id = identification;

		}

		void printPerson(){
			std::cout<< "Name: " << lastName << ", " << firstName << "\nID: " << id << "\n"; 
		}
	
};

class Student : public Person{

	private:
		std::vector<int> testScores;  

	public:
    Student(std::string firstName, std::string lastName, int id, std::vector<int> scores) : Person(firstName, lastName, id){
      this->testScores = scores;
    }

    char calculate(){
            
      int sumScore = 0;
      for(int i = 0; i < testScores.size(); i++){
        sumScore += testScores[i];
      }
      int averageScore = sumScore / testScores.size();
        
      if(averageScore <= 100 && averageScore >= 90){
        return 'O';
      }
      else if(averageScore < 90 && averageScore >= 80){
        return 'E';
      }
      else if(averageScore < 80 && averageScore >= 70){
        return 'A';
      }
      else if(averageScore < 70 && averageScore >= 55){
        return 'P';
      }
      else if(averageScore < 55 && averageScore >= 40){
        return 'D';
      }
      return 'T';

    }
        
};

int main(){

	std::string firstName;
  std::string lastName;
	int id;
  int numScores;

	std::cin >> firstName >> lastName >> id >> numScores;

  std::vector<int> scores;

  for(int i = 0; i < numScores; i++){

	  int tmpScore;
	  std::cin >> tmpScore;
		scores.push_back(tmpScore);
    
	}

	Student* s = new Student(firstName, lastName, id, scores);
	s->printPerson();

	std::cout << "Grade: " << s->calculate() << "\n";

	return 0;

}