using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;

namespace dll_gui
{
    public class GUI_IF
    {
        static VMDataContainer data_container = new VMDataContainer();
        static Thread gui_thread;
        
        public static void start_gui()
        {
            try
            {
                /*
                Thread thread = new Thread(new ThreadStart(GuiEntry));
                thread.SetApartmentState(ApartmentState.STA);
                //
                Console.WriteLine("GUI thread start!");
                thread.Start();
                //
                while (thread.ThreadState == ThreadState.Running)
                {
                    Console.WriteLine("X: {0}", data_container.X);
                    Thread.Sleep(1000);
                }
                */
                gui_thread = new Thread(new ThreadStart(GuiEntry));
                gui_thread.SetApartmentState(ApartmentState.STA);
                gui_thread.Start();
            }
            catch (Exception e)
            {
                Console.WriteLine(e);
            }
        }

        public static void end_gui()
        {
            gui_thread.Join();
        }

        public static bool gui_is_active()
        {
            return (gui_thread.ThreadState == ThreadState.Running);
        }

        static void GuiEntry()
        {
            
            UserControl1 wnd = new UserControl1(data_container);
            wnd.ShowDialog();
        }


        public static int get_value()
        {
            return data_container.X;
        }
    }

}
