// Bridge Design Patttern
#include <bits/stdc++.h>

using namespace std;

class Theme {
    public: 
        virtual string getColor() = 0;
};

class DarkTheme : public Theme {
    public: 
        string getColor() {
            return "dark theme";
        }

};

class LightTheme : public Theme {
    public: 
        string getColor() {
            return "light theme";
        }

};

class AquaTheme : public Theme {
    public: 
        string getColor() {
            return "aqua theme";
        }

};

class WebPage {

    protected:
        Theme *theme;


    public: 

        WebPage() {}

        WebPage(Theme *theme) {
            this->theme = theme;
        }

        virtual string getContent() = 0;
        
        string getThemeInfo() {
            return this->theme->getColor();
        }

};

class AboutPage : public WebPage {
    public: 

        AboutPage(Theme *theme) {
            this->theme = theme;
        }

        string getContent() {
            return "about page";
        }

};

class HomePage : public WebPage {

    public: 

        HomePage(Theme *theme) {
            this->theme = theme;
        }

        string getContent() {
            return "home page";
        }

};


int main() {

    Theme *darkTheme = new DarkTheme();
    Theme *lightTheme = new LightTheme();
    WebPage *homePage = new HomePage(darkTheme);
    WebPage *aboutPage = new AboutPage(lightTheme);

    cout << "page content :: " << homePage->getContent() << " theme :: " << homePage->getThemeInfo() << endl;
    cout << "page content :: " << aboutPage->getContent() << " theme :: " << aboutPage->getThemeInfo() << endl;

}