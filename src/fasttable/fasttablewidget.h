#ifndef FASTTABLEWIDGET_H
#define FASTTABLEWIDGET_H

#include "customfasttablewidget.h"

//------------------------------------------------------------------------------

class FastTableWidget : public CustomFastTableWidget
{
    Q_OBJECT

public:
    explicit FastTableWidget(QWidget *parent = 0);
    ~FastTableWidget();

    void clearTable();

    void resetBackgroundBrushes();
    void resetForegroundColors();
    void resetFonts();
    void resetTextFlags();

    void resetBackgroundBrush(const int row, const int column);
    void resetForegroundColor(const int row, const int column);
    void resetFont(const int row, const int column);
    void resetTextFlag(const int row, const int column);

    void setRowCount(int count);
    void setColumnCount(int count);

    QBrush backgroundBrush(const int row, const int column);
    void setBackgroundBrush(const int row, const int column, const QBrush brush);

    QColor foregroundColor(const int row, const int column);
    void setForegroundColor(const int row, const int column, const QColor color);

    QFont cellFont(const int row, const int column);
    void setCellFont(const int row, const int column, const QFont font);

    int cellTextFlags(const int row, const int column);
    void setCellTextFlags(const int row, const int column, const int flags);

    void clearSpans();
    void setSpan(const int row, const int column, quint16 rowSpan, quint16 columnSpan);
    quint16 rowSpan(const int row, const int column);
    quint16 columnSpan(const int row, const int column);
    QPoint spanParent(const int row, const int column);

protected:
    QList< QList<QBrush *> > mBackgroundBrushes;
    QList< QList<QColor *> > mForegroundColors;
    QList< QList<QFont *> > mCellFonts;
    QList< QList<int> > mCellTextFlags;
    QList< QList<quint16> > mCellMergeX;
    QList< QList<quint16> > mCellMergeY;
    QList< QList<int> > mCellMergeParentRow;
    QList< QList<int> > mCellMergeParentColumn;

    void paintEvent(QPaintEvent *event);
    void paintCell(QPainter &painter, const int x, const int y, const int width, const int height, const int row, const int column);

    void updateVisibleRange();
};

#endif // FASTTABLEWIDGET_H
