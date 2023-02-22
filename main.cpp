#include <iostream>
#include <memory>
#include <tuple>

//Абстрактная фабрика
class Button {
public:
    virtual void paint() = 0;
    virtual ~Button() {}
};

class WinButton : public Button {
public:
    void  paint() override {
        std::cout << "Paint Windows Button\n";
    }
};

class MacButton : public Button {
public:
    void  paint() override {
        std::cout << "Paint Mac Button\n";
    }
};

class Checkbox {
public:
    virtual void paint() = 0;
    virtual ~Checkbox(){}
};

class WinCheckbox: public Checkbox {
public:
    void paint() override {
        std::cout << "Paint Windows Checkbox";
    }    
};

class MacCheckbox : public Checkbox {
public:
    void paint() override {
        std::cout << "Paint Mac Checkbox";
    }
};

class GUIFactory {
public:
    virtual std::shared_ptr<Button> createButton() = 0;
    virtual std::shared_ptr<Checkbox> createCheckbox() = 0;
    virtual ~GUIFactory() {}
};

class MacFactory : public GUIFactory {
public:
    std::shared_ptr<Button> createButton() {
        return std::make_shared<MacButton>();
    }
    std::shared_ptr<Checkbox> createCheckbox() {
        return std::make_shared<MacCheckbox>();
    }
};

class WinFactory : public GUIFactory {
public:
    std::shared_ptr<Button> createButton() {
        return std::make_shared<WinButton>();
    }
    std::shared_ptr<Checkbox> createCheckbox() {
        return std::make_shared<WinCheckbox>();
    }
};

class Application {
public:
    Application(std::shared_ptr<GUIFactory> factory) {
        _factory = factory;
    }
    void createUI() {
        _button = _factory->createButton();
        _checkbox = _factory->createCheckbox();
    }
    void paint() {
        _button->paint();
        _checkbox->paint();
    }
private:
    std::shared_ptr<GUIFactory> _factory;
    std::shared_ptr<Button> _button;
    std::shared_ptr<Checkbox> _checkbox;
};


int main()
//Абстрактная фабрика
{/*
    std::string config;
    std::shared_ptr<GUIFactory> factory;
    std::cout << "Enter platform (Mac, Windows): ";
    std::cin >> config;
    if (config == "Mac") {
        factory = std::make_shared<MacFactory>();
    }
    else if (config == "Windows") {
        factory = std::make_shared<WinFactory>();
    }
    std::shared_ptr<Application> app = std::make_shared<Application>(factory);
    app->createUI();
    app->paint();
    */

    //Tuple
    std::tuple<int, float, std::string> t { 5, 4.2f, "hello" };
    std::cout << std::get<0>(t);
}