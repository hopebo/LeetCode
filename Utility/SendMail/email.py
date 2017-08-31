#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
@file email.py
@author libo44(@baidu.com)
@date 2017.8.31
"""

import subprocess
import time
import urllib
import sys
import base64
import urllib2
from datetime import *

class Email(object):
    """
    @brief
    """
    def __init__(self, content, head, date, receiver):
        """
        @brief
        """
        self.content = content
        self.head = head
        self.date = date
        self.receiver = receiver
    
    def print_html(self):
        """
        @brief
        """
        self.tags = []
        self.tags.append("<html>")
        self.tags.append("<br/>")
        self.tags.append("<form>")
        self.tags.append('<a href="ucp.baidu.com" target = "_blank"> %s--%s </a>' % (self.head, self.date))
        self.tags.append("</form>")
        self.tags.append("<hr/>")
        self.tags.append("<body>")
        self.tags.append("<table border=1 cellpadding=4 cellspacing=0>")
        for row in self.content:
            self.tags.append(self.format(row))
        self.tags.append("</table><br />")
        self.tags.append("</body>")
        self.tags.append("</html>")

    def format(self, row):
        """
        @brief
        """
        row_tag = []
        row_tag.append("<tr>")
        data_head = "<td width='600px' style='white-space:nowrap;'>"
        data_tail = "</td>"
        for item in row:
            row_tag.append(data_head + item + data_tail)
        return '\n'.join(row_tag)

    def send(self):
        """
        @brief
        """
        self.print_html()
        html = '\n'.join(self.tags)
        receiver = ' '.join(self.receiver)
        subject = "%s--%s" % (self.head, self.date)
        subject = base64.b64encode(subject)
        send_mail = 'formail -I  "MIME-Version:1.0" -I "Content-type:text/html;charset=utf-8" -I "Subject:=?utf-8?B?%s?=" -I "TO:%s" | /usr/sbin/sendmail %s' % (subject, receiver, receiver)
        sub = subprocess.Popen(send_mail, shell=True, stdin=subprocess.PIPE)
        slice_num = sub.communicate(html)
