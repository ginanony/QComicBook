/*
 * This file is a part of QComicBook.
 *
 * Copyright (C) 2005-2006 Pawel Stolowski <pawel.stolowski@wp.pl>
 *
 * QComicBook is free software; you can redestribute it and/or modify it
 * under terms of GNU General Public License by Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY. See GPL for more details.
 */

#include "PageNumberEdit.h"
#include <QValidator>

using namespace QComicBook;

PageNumberEdit::PageNumberEdit(QWidget *parent, int val, int max): QLineEdit(parent)
{
	//setMaxLength(3);
	//setFocusPolicy(QWidget::ClickFocus);
	validator = new QIntValidator(1, max, this);
	setValidator(validator);
	if (val<1)
		val = 1;
	else if (val>max)
		val = max;
	setText(QString::number(val));
	connect(this, SIGNAL(returnPressed()), this, SLOT(onReturn()));
}

PageNumberEdit::~PageNumberEdit()
{
}

void PageNumberEdit::setMax(int n)
{
	validator->setTop(n);
}

void PageNumberEdit::onReturn()
{
	emit pageSelected(pageNumber());
}

int PageNumberEdit::pageNumber() const
{
	return text().toInt() - 1;
}

void PageNumberEdit::selectAll()
{
	//do nothing - just override default QLineEdit behavior
}

