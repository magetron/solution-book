class Person {
public:
    string name;
    int age;

    Person () { }

    Person (string& n, int a) : name(n), age(a) { }

    virtual void getdata () {
        cin >> name >> age;
    }

    virtual void putdata () {
        cout << name << " " << age << " ";   
    }

};

class Professor : public Person {
public:
    static int id_count;

    int publications = 0, cur_id = -1;

    Professor () : cur_id(id_count++) { }

    Professor (string& n, int a, int pub) : Person(n, a), publications(pub), cur_id(id_count++) { }

    void getdata () {
        Person::getdata();
        cin >> publications;
    }
    
    void putdata () {
        Person::putdata();
        cout << publications << " " << cur_id << endl;
    }

};

int Professor::id_count = 1;

class Student : public Person {
public: 
    static int id_count;

    vector<int> marks;
    int cur_id = -1;

    Student () : cur_id(id_count++) { 
        marks = vector<int>(6, -1);
    }

    Student (string& n, int a, vector<int>& m) : Person(n, a), marks(m), cur_id(id_count++) { }

    void getdata () {
        Person::getdata();
        int sum = 0;
        for (int i = 0; i < 6; i++) {
            cin >> marks[i];
            sum += marks[i];
        }
        marks.push_back(sum);
    }

    void putdata () {
        Person::putdata();
        cout << marks.back() << " " << cur_id << endl;
    };

};

int Student::id_count = 1;



