# offline_judge

���⣺
onlinejudge�м�������

1����������һ�㶼�Ǳ��ܵģ��û��޷���ò������ݣ������ڱ��ص��ԡ���Щoj��leetcode��һЩʾ�����ݣ����ǲ��ࡣ

2����Щoj��leetcode��ÿ����Ŀ�����붼��һ�����ڱ��ص��Ե�ʱ����Ҫ�����ݵ�ת�������鷳

3����ЩojҪ�շѣ�����leetcode

4����Щoj���������ʱ��û���ṩ��Ӧ���������ݣ��û��޷�֪�������ԭ��

�ܵ���˵���кܶ����⣬�û�����ܲ��á�

���������

��Ҫ˼����ͨ�����������̶��Ĳ����������ݣ���dmoj���Եõ�ָ����Ŀ����ȷ���룬������ȷ���룬���У��Ϳ��Եõ������õĲο�������ݣ���Ϊ�����Լ�д����Ĳο���

dmoj 

��Ҫ�����ǣ� ��https://dmoj.ca/problem/16bitswonly Ϊ��

ʹ��ϵͳ��windows

ʹ��IDE��Visual Studio2022��ԭ����֧��c++17������ʹ��stl��filesystem�⡣���Ұ�װ���Microsoft Child Process Debugging Power Tool�����������ӽ��̡�

1��ͨ����̵ķ�ʽ������������������ݣ����߹̶�����Ҳ���ԣ��ο�problem/16bitswonly/input.cpp�ļ���

2����½dmoj��վ���� https://dmoj.ca/problem/16bitswonly �ϵ���ȷ���뿽������������Ϊproblem/16bitswonly/main.cpp�ļ�

3���޸�CMakeLists.txt����ӵ������б��

4���Ҽ�ѡ��CMakeLists.txt,��ӵ������ã�������ʾ��

{
  "version": "0.2.1",
  "defaults": {},
  "configurations": [
    {
      "type": "default",
      "project": "CMakeLists.txt",
      "projectTarget": "Engine.exe",
      "name": "debug 16bitswonly",
      "args": [ "16bitswonly" ]
    }
  ]
}

5���ڲ˵��� ����->��������Ŀ��->Child Process Debugging Settings����ѡ�� 

6����contest/16bitswonly��дmain.cpp������д�����¶ϵ�����ˡ����Գɹ����Ϳ���ֱ���ύ��dmoj��