#ifndef CPP_EX2_FRACTAL_DRAWERE_H
#define CPP_EX2_FRACTAL_DRAWERE_H

class Parser {
public:
    void doesFileExist(const std::string &fPath) const;

    void inputValidity(int argc, char *argv[]) const;

    std::vector<Fractal *> &parseFile(std::string &path, std::vector<Fractal *> &f) const;

    void parseError() const;

    void dimValidity(int dim) const;

    void typeValidity(int type) const;

    void checkIfInt(std::string &c) const;

    void lineValidity(std::vector<std::string> &input) const;

    Fractal* factory(int type, int dim) const;

};


#endif //CPP_EX2_FRACTAL_DRAWERE_H