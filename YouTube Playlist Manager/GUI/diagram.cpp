#include "headers/diagram.h"
#include "ui_headers/ui_diagram.h"

#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

QT_CHARTS_USE_NAMESPACE

Diagram::Diagram(QWidget *parent, CSVRepo *repo) :
        QDialog(parent),
        ui(new Ui::Diagram) {

    this->repo = repo;

    QPieSeries *series = new QPieSeries();

    std::vector<Tutorial> *v = this->repo->getTutorials();
    if (v->empty()) return;
    int i=0;
    for (auto &it : *v) {
        series->append(it.getTitle().c_str(),it.getNoViews());
        QPieSlice *slice = series->slices().at(i);
        slice->setLabelVisible();
        i++;
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Tutorials pie chart by views");
    chart->legend()->hide();

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QPieSeries *series2 = new QPieSeries();

    std::vector<Tutorial> *v2 = this->repo->getTutorials();
    if (v2->empty()) return;
    int i2=0;
    for (auto &it : *v2) {
        series2->append(it.getTitle().c_str(),it.getNoLikes());
        QPieSlice *slice = series2->slices().at(i2);
        slice->setLabelVisible();
        i2++;
    }

    QChart *chart2 = new QChart();
    chart2->addSeries(series2);
    chart2->setTitle("Tutorials pie chart by likes");
    chart2->legend()->hide();

    QChartView *chartView2 = new QChartView(chart2);
    chartView2->setRenderHint(QPainter::Antialiasing);

    QVBoxLayout *lay = new QVBoxLayout(this);
    lay->addWidget(chartView);
    lay->addWidget(chartView2);

    ui->setupUi(this);
}

Diagram::~Diagram() {
    delete ui;
}

