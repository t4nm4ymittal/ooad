#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Room {
private:
string name;
public:
Room(string name) {
this->name = name;
}

string getName() {
return name;
}#include<iostream>
#include<vector>

#include<string>
using namespace std;
class Room {
private:
string name;
public:
Room(string name) {
this->name = name;
}

string getName() {
return name;
}
};
class House {
private:
string name;
vector<Room*> rooms;
public:
House(string name) {
this->name = name;
}return name;
}
vector<Room*> getRooms() {
return rooms;
}
~House() {
for (int i = 0; i < rooms.size(); i++) {
cout<<"deleting "<<rooms[i]->getName()<<endl;
delete rooms[i];
}
cout<<"Delete all the respected rooms"<<endl;
}
};
int main() {
cout<<"Enter name of your house"<<endl;
string h;
cin>>h;
House* house = new House(h);

cout<<"Enter number of rooms"<<endl;
int n;
cin>>n;
while(n--)
{
cout<<"Enter name of your room"<<endl;
string r1;
cin>>r1;
Room* r = new Room(r1);
house->addRoom(r);
}

cout<<"House created with the name: "<<house->getName()<<endl;
cout<<"Display the detail of house:"<<endl;
cout<<"Name: "<<house->getName()<<endl;
cout<<"No of rooms with specification: "<<endl;
vector<Room*> rooms = house->getRooms();
for (int i = 0; i < rooms.size(); i++) {
cout<<rooms[i]->getName()<<endl;
}
delete house;
cout<<"Delete the house"<<endl;
return 0;
}

void addRoom(Room* room) {
rooms.push_back(room);
}
string getName() {
return name;
}
vector<Room*> getRooms() {
return rooms;
}
~House() {
for (int i = 0; i < rooms.size(); i++) {
cout<<"deleting "<<rooms[i]->getName()<<endl;
delete rooms[i];
}
cout<<"Delete all the respected rooms"<<endl;
}

};
int main() {
cout<<"Enter name of your house"<<endl;
string h;
cin>>h;
House* house = new House(h);
cout<<"Enter number of rooms"<<endl;
int n;
cin>>n;
while(n--)
{
cout<<"Enter name of your room"<<endl;
string r1;
cin>>r1;
Room* r = new Room(r1);
house->addRoom(r);
}

cout<<"House created with the name: "<<house->getName()<<endl;
cout<<"Display the detail of house:"<<endl;
cout<<"Name: "<<house->getName()<<endl;
cout<<"No of rooms with specification: "<<endl;
vector<Room*> rooms = house->getRooms();
for (int i = 0; i < rooms.size(); i++) {
cout<<rooms[i]->getName()<<endl;
}
delete house;
cout<<"Delete the house"<<endl;
return 0;
}
