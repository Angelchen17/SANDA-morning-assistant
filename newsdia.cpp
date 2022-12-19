#include "newsdia.h"
#include "ui_newsdia.h"

/**
 * @brief      Constructs a new instance.
 *
 * @param      parent  The parent
 */
NewsDia::NewsDia(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewsDia)
{
    ui->setupUi(this);
}

/**
 * @brief      Destroys the object.
 */
NewsDia::~NewsDia()
{
    delete ui;
}

/**
 * @brief      Called when push button clicked.
 */
void NewsDia::on_pushButton_clicked(){
    newsnum = ui->spinBox->value();
    std::cout << "Number of News:" << newsnum;
    news newNews(newsnum);
    std::string newsinfo;
    //int num;
    //QTextBrowser *browser = new QTextBrowser();
    //browser->setPlainText(" ");
    //browser->append(QString::number(count));
    //std::vector<NewsObj> newsobj = newNews.get_news();
    for(int j=0; j< newsnum; j++){
        newsinfo += "\nTitle: " + newNews.get_news()[j].get_title() + "\nDescription: " + newNews.get_news()[j].get_descrip() + "\nDate: " + newNews.get_news()[j].get_date() + "\nUrl: " + newNews.get_news()[j].get_url() + "\n\n";
        //ui->textBrowser->setText(QString::fromStdString(newNews.get_news()[j].get_title()) + "\n");
        //ui->textBrowser->setText(QString::fromStdString(newNews.get_news()[j].get_descrip()) + "\n");
        //ui->textBrowser->setText(QString::fromStdString(newNews.get_news()[j].get_date()) + "\n");
        //ui->textBrowser->setText(QString::fromStdString(newNews.get_news()[j].get_url()) + "\n\n\n");
    }
    //ui->textBrowser->setText(browser);
    const QString msg = QString::fromStdString(newsinfo);
    QMessageBox::information(this,"Message", msg, QMessageBox::Ok);


}
