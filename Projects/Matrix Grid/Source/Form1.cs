using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Threading;


namespace CounterThread
{
    public partial class Form1 : Form
    {
        public int m_Width;
        public int m_Height;
        public int m_NoOfRows;
        public int m_NoOfCols;
        public int m_XOffset;
        public int m_YOffset;
        public int m_iCounter = 2;
        public int m_iMaxSize = 3;
        public const int DEFAULT_X_OFFSET = 100;
        public const int DEFAULT_Y_OFFSET = 50;
        public const int DEFAULT_NO_ROWS = 3;
        public const int DEFAULT_NO_COLS = 3;
        public const int DEFAULT_WIDTH = 60;
        public const int DEFAULT_HEIGHT = 60;
        public Form1()
        {
            Initialize();
            InitializeComponent();
            bThreadStatus = false;
        }

        private void startToolStripMenuItem_Click(object sender, EventArgs e)
        {
            CounterThread = new Thread(new ThreadStart(ThreadCounter));
            CounterThread.Start();
            bThreadStatus = true;
                
        }
        public void ThreadCounter()
        {
            //long m_iCounter = 0;
            try
            {
                while (true)
                {
                    m_iCounter++;
                    if(m_iCounter>m_iMaxSize)
                    {
                        m_iCounter = 1;
                    }
                    Invalidate();
                   labelCounter.Invoke(new MethodInvoker(delegate { labelCounter.Text = m_iCounter.ToString(); }));
                    labelCounter.Text = m_iCounter.ToString();
                    
                    Thread.Sleep(500);
                }
            }
            catch (Exception ex)
            {

            }
        }

        private void pauseToolStripMenuItem_Click(object sender, EventArgs e)
        {
            CounterThread.Suspend();
        }

        private void resumeToolStripMenuItem_Click(object sender, EventArgs e)
        {
            CounterThread.Resume();
        }

        private void OnPaint(object sender, EventArgs e)
        {
            DrawGrid();
        }
        public void Initialize()
        {
            //Put all the default values
            m_NoOfRows = DEFAULT_NO_ROWS;
            m_NoOfCols = DEFAULT_NO_COLS;
            m_Width = DEFAULT_WIDTH;
            m_Height = DEFAULT_HEIGHT;
            m_XOffset = DEFAULT_X_OFFSET;
            m_YOffset = DEFAULT_Y_OFFSET;

        }
        private void DrawGrid()
        {
            Graphics boardLayout = this.CreateGraphics();
            Pen layoutPen = new Pen(Color.BlueViolet);
            layoutPen.Width = 2;

            //boardLayout.DrawLine(layoutPen, 0, 0, 100, 0);
            int X = DEFAULT_X_OFFSET;
            int Y = DEFAULT_Y_OFFSET;
            //Draw The rows
            for (int i = 0; i <=m_iCounter; i++)
            {
                boardLayout.DrawLine(layoutPen, X, Y, X + this.m_Width * this.m_iCounter, Y);
                Y = Y + this.m_Height;
            }

            //Draw The Cols
            X = DEFAULT_X_OFFSET;
            Y = DEFAULT_Y_OFFSET;
            for (int j = 0; j <= m_iCounter; j++)
            {
                boardLayout.DrawLine(layoutPen, X, Y, X, Y + this.m_Height * this.m_iCounter);
                X = X + this.m_Width;
            }

        }

        private void menuItem50_Click(object sender, System.EventArgs e)
        {
           m_Width = DEFAULT_WIDTH / 2;
           m_Height = DEFAULT_HEIGHT / 2;
            this.Refresh();
        }

        private void menuItem100_Click(object sender, System.EventArgs e)
        {
            m_Width = DEFAULT_WIDTH;
            m_Height = DEFAULT_HEIGHT;
            this.Refresh(); //Call Onpaint
        }

        private void menuItem200_Click(object sender, System.EventArgs e)
        {
            m_Width = DEFAULT_WIDTH * 2;
            m_Height = DEFAULT_HEIGHT * 2;
            this.Refresh(); //Call Onpaint
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void toolStripMenuItem2_Click(object sender, EventArgs e)
        {
           //matrix max size=3
            m_iMaxSize = 3;
            this.Refresh();
        }  
        private void toolStripMenuItem3_Click(object sender, EventArgs e)
        {
             //matrix max size=4
            m_iMaxSize = 4
                ;
            this.Refresh();
        }

        private void toolStripMenuItem4_Click(object sender, EventArgs e)
        {
            //matrix max size=5
            m_iMaxSize = 5;
            this.Refresh(); ;
        }

        private void gridSizeToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }
    }
}
