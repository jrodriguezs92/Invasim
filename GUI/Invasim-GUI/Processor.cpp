#include "Processor.h"
#include <QBrush>

Processor::Processor(QGraphicsItem *parent, int coo_x, int coo_y, std::string json_file, int x_size, int y_size) :
    QGraphicsRectItem(parent),
    coo_x(coo_x),
    coo_y(coo_y),
    json_file(json_file)
{
    setRect(0, 0, x_size, y_size);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(QColor("grey"));
    setBrush(brush);

    this->ilet_id = -1;
    this->state = "FREE";
    this->load = 0;
}

void Processor::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    ProcessorInfo *diag = new ProcessorInfo();
    diag->set_data(coo_x, coo_y, ilet_id, load, state);
    diag->setModal(true);
    diag->exec();
    delete diag;
    QGraphicsRectItem::mousePressEvent(event);
}

void Processor::update_data(unsigned int cycle)
{
    std::string line;
    std::ifstream r_file(this->json_file);
    std::getline(r_file, line);
    r_file.close();
    JSON new_data = JSON::parse(line);

    this->ilet_id = new_data[cycle]["ILet"];
    this->load = new_data[cycle]["Load"];
    this->state = new_data[cycle]["State"];
    if(this->ilet_id == -1)
        this->json_data->setPlainText("N/A");
    else
        this->json_data->setPlainText((std::to_string(this->ilet_id).c_str()));
}

void Processor::update_color(QVector<QColor> *ilet_colors_ptr)
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    if(this->ilet_id != -1)
        brush.setColor(ilet_colors_ptr->at(this->ilet_id));
    else
        brush.setColor(QColor("grey"));
    setBrush(brush);
}
