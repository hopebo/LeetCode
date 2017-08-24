#!/usr/bin/env python
# -*- coding: utf-8 -*-

import subprocess
import time
import urllib
import sys
import base64
import urllib2
from datetime import *

def format_table(cols, btag = '', etag = ''):
    format = "<tr>"
    td_header = "<td style='white-space:nowrap;'>"
    i = 0
    for item in cols:
        try:
            if i == 4 and int(item) < 0:
                btag = '<span style="color:red">'
                etag = '</span>'
            format += td_header + btag + str(item) + etag + "</td>"
        except:
            format += td_header + btag + str(item) + etag + "</td>"
        i += 1
    format += "</tr>"
    return format

def print_html(data, fields, date):
    tags = []
    tags.append("<html>")
    tags.append("<br/>")
    tags.append('<form>')
    tags.append('<a href="ucp.baidu.com" target = "_blank"> 统一内容池--%s 模块时效性报表</a>' % (date))
    tags.append('</form>')
    tags.append("<hr/>")
    tags.append("<head>")
    tags.append("<title> 统一内容池模块时效性</title>")
    tags.append('<meta http-equiv="Content-Type" Content="text/html"; charset="gbk"/>')
    tags.append("</head>")
    tags.append("<body>")
    tags.append("<b>数据总量: %d</b>" % (data['total']))
    tags.append("<table border=1 cellpadding=4 cellspacing=0>")
    tags.append(format_table(fields))
    for item in (10,50,80,90,95,99,99.9,99.99):
        data[item].insert(0, item)
        tags.append(format_table(data[item]))
    data['average'].insert(0,'average')
    tags.append(format_table(data['average']))
    tags.append("</table><br />")
    tags.append("</body>")
    tags.append("</html>")
    return tags
    
def main(data, date):
    fields =["分位点(%)\时延(s)", "news_tagger", "ucp_merger",
            "mobile_sender", "hub_sender", "hub_publish", "bjh2sb_sender"]
    lines = print_html(data, fields, date)
    html  = '\n'.join(lines)
    users =["ucp@baidu.com", "libo44@baidu.com"]
    users = str(' '.join(set(users)))
    subject = "统一内容池--%s 模块时效性报表" % (date)
    subject = base64.b64encode(subject)
    send_mail = 'formail -I  "MIME-Version:1.0" -I "Content-type:text/html;charset=utf-8" -I "Subject:=?utf-8?B?%s?=" -I "TO:%s" | /usr/sbin/sendmail %s' % (subject, users, users)
    sub = subprocess.Popen(send_mail, shell=True, stdin=subprocess.PIPE)
    slice_num = sub.communicate(html)
