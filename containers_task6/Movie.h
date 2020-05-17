//
// Created by Sophia Shuvar on 15.05.20.
//

#ifndef CONTAINERS_TASK6_MOVIE_H
#define CONTAINERS_TASK6_MOVIE_H

#endif //CONTAINERS_TASK6_MOVIE_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;
//назва фільму, жанр, режисер, кіностудія, список акторів.
class Movie {
private:
    string movie_name;
    string genre;
    string director;
    string studio;
    vector<string> actors;

public:
    Movie(){}
    Movie(string _movie_name, string _genre, string _director, string _studio,  vector<string> _actors): movie_name(_movie_name),
                                                                                                        genre(_genre), director(_director), studio(_studio), actors(_actors){}
    ~Movie(){actors.clear();};

    friend istream & operator>>(istream & is, Movie & a) {
        //if(!a.actors.empty()) (a.actors).clear();
        unsigned el = 0; string actor;
        is >> a.movie_name >> a.genre >> a.director >> a.studio >> el;
        a.actors.resize(el);
        for (size_t i = 0; i < el; i++) is >> a.actors[i];
        return is;
    }


    friend ostream & operator<<(ostream & os, const Movie & a) {
        os << "movie_name: " << a.movie_name << ", genre: " << a.genre
           << ", director: " << a.director << ", studio: " << a.studio << ", actors: ";

        for (auto& i : a.actors) os << i << " ";
        return os;
    }

    const string &getMovie_name() const {
        return movie_name;
    }

    const string &getGenre() const {
        return genre;
    }

    const string &getDirector() const {
        return director;
    }

    const string &getStudio() const {
        return studio;
    }

    const vector<string> &getActors() const {
        return actors;
    }

    friend bool operator <(const Movie &a,  Movie b){
        return (a.genre == b.genre) ? (a.studio == b.studio ? a.movie_name < b.movie_name : a.studio < b.studio): (a.genre < b.genre);
    }
};