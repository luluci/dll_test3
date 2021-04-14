using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.ComponentModel;

namespace dll_gui
{
    public class VMDataContainer : INotifyPropertyChanged
    {

        public VMDataContainer()
        {
            this.X = 11;
        }


        public int X { get; set; }
        

        public event PropertyChangedEventHandler PropertyChanged;

        public void NotifyPropertyChanged(string PropertyName)
        {
            var e = new PropertyChangedEventArgs(PropertyName);
            PropertyChanged?.Invoke(this, e);
        }
    }
}
