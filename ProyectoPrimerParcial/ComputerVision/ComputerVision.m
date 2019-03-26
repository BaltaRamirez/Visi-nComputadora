function varargout = ComputerVision(varargin)
% COMPUTERVISION MATLAB code for ComputerVision.fig
%      COMPUTERVISION, by itself, creates a new COMPUTERVISION or raises the existing
%      singleton*.
%
%      H = COMPUTERVISION returns the handle to a new COMPUTERVISION or the handle to
%      the existing singleton*.
%
%      COMPUTERVISION('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in COMPUTERVISION.M with the given input arguments.
%
%      COMPUTERVISION('Property','Value',...) creates a new COMPUTERVISION or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before ComputerVision_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to ComputerVision_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help ComputerVision

% Last Modified by GUIDE v2.5 25-Mar-2019 23:57:11

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @ComputerVision_OpeningFcn, ...
                   'gui_OutputFcn',  @ComputerVision_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before ComputerVision is made visible.
function ComputerVision_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to ComputerVision (see VARARGIN)

% Choose default command line output for ComputerVision
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);


% UIWAIT makes ComputerVision wait for user response (see UIRESUME)
% uiwait(handles.visionGUI);


% --- Outputs from this function are returned to the command line.
function varargout = ComputerVision_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on selection change in menu.
function menu_Callback(hObject, eventdata, handles)
%funcion =  get(hObject, 'String');
opcion = get(hObject, 'Value');

switch opcion
    case 1
        
        set(handles.tablaHistograma,'Visible','off');   %para desaparecer la tabla de operaciones geometricas
        set(handles.imagenEntrada,'Visible','off');
        set(handles.linearTransformation,'Visible','off');
        set(handles.logarithmicTransformation,'Visible','off');
        set(handles.powerLawTransformation,'Visible','off');
        set(handles.cargarImagen,'Visible','off');
        set(handles.imagenEntrada,'Visible','off');
        cla(handles.salida1);
        cla(handles.salida2);
        cla(handles.salida3);
        cla(handles.imagenEntrada);
        set(handles.cargarImagenPT,'Visible','off');
        set(handles.cargarImagenHist,'Visible','off');
        set(handles.contrastStretching,'Visible','off');
        set(handles.intensityLevelSlicing,'Visible','off');
        set(handles.histogram,'Visible','off');
        set(handles.tablaHistograma,'Visible','off');
        set(handles.histogramMatching,'Visible','off');


    case 2
        set(handles.tablaHistograma,'Visible','off');    %para aparecer la tabla de operaciones geometricas
       
        set(handles.imagenEntrada,'Visible','off');
        set(handles.linearTransformation,'Visible','off');
        set(handles.logarithmicTransformation,'Visible','off');
        set(handles.powerLawTransformation,'Visible','off');
        set(handles.cargarImagen,'Visible','off');
        set(handles.imagenEntrada,'Visible','off');
        cla(handles.salida1);
        cla(handles.salida2);
        cla(handles.salida3);
        cla(handles.imagenEntrada);
        set(handles.cargarImagenPT,'Visible','off');
        set(handles.cargarImagenHist,'Visible','off');
        set(handles.contrastStretching,'Visible','off');
        set(handles.intensityLevelSlicing,'Visible','off');
        set(handles.histogram,'Visible','off');
        set(handles.tablaHistograma,'Visible','off');
        set(handles.histogramMatching,'Visible','off');
    
    case 3
       
        set(handles.tablaHistograma,'Visible','off');
        set(handles.cargarImagen,'Visible','on');
        set(handles.linearTransformation,'Visible','off');
        set(handles.logarithmicTransformation,'Visible','off');
        set(handles.powerLawTransformation,'Visible','off');
        set(handles.imagenEntrada,'Visible','off');
        set(handles.cargarImagenPT,'Visible','off');
        set(handles.cargarImagenHist,'Visible','off');
        set(handles.contrastStretching,'Visible','off');
        set(handles.intensityLevelSlicing,'Visible','off');
        set(handles.histogram,'Visible','off');
        set(handles.tablaHistograma,'Visible','off');
        set(handles.histogramMatching,'Visible','off');
        

    case 4
       
        set(handles.tablaHistograma,'Visible','off');
        set(handles.linearTransformation,'Visible','off');
        set(handles.logarithmicTransformation,'Visible','off');
        set(handles.powerLawTransformation,'Visible','off');
        set(handles.cargarImagen,'Visible','off');
        set(handles.imagenEntrada,'Visible','off');
        cla(handles.salida1);
        cla(handles.salida2);
        cla(handles.salida3);
        cla(handles.imagenEntrada);
        set(handles.cargarImagenPT,'Visible','on');
        set(handles.cargarImagenHist,'Visible','off');
        set(handles.histogram,'Visible','off');
        set(handles.tablaHistograma,'Visible','off');
        set(handles.histogramMatching,'Visible','off');
   
        
    case 5
       
        set(handles.tablaHistograma,'Visible','off');
        set(handles.linearTransformation,'Visible','off');
        set(handles.logarithmicTransformation,'Visible','off');
        set(handles.powerLawTransformation,'Visible','off');
        set(handles.cargarImagen,'Visible','off');
        cla(handles.salida1);
        cla(handles.salida2);
        cla(handles.salida3);
        cla(handles.imagenEntrada);
        set(handles.cargarImagenPT,'Visible','off');
        set(handles.cargarImagenHist,'Visible','on');
        set(handles.contrastStretching,'Visible','off');
        set(handles.intensityLevelSlicing,'Visible','off');

    case 6
        
        set(handles.tablaHistograma,'Visible','off');
        set(handles.linearTransformation,'Visible','off');
        set(handles.logarithmicTransformation,'Visible','off');
        set(handles.powerLawTransformation,'Visible','off');
        set(handles.cargarImagen,'Visible','off');
        set(handles.imagenEntrada,'Visible','off');
        cla(handles.salida1);
        cla(handles.salida2);
        cla(handles.salida3);
        cla(handles.imagenEntrada);
        set(handles.cargarImagenPT,'Visible','off');
        set(handles.cargarImagenHist,'Visible','off');
        set(handles.contrastStretching,'Visible','off');
        set(handles.intensityLevelSlicing,'Visible','off');
        set(handles.histogram,'Visible','off');
        set(handles.tablaHistograma,'Visible','off');
        set(handles.histogramMatching,'Visible','off');

end

% --- Executes during object creation, after setting all properties.
function menu_CreateFcn(hObject, eventdata, handles)
% hObject    handle to menu (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in cargarImagen.
function cargarImagen_Callback(hObject, eventdata, handles)
        
        %set(handles.imagenEntrada,'Visible','on');  %activar la vista de la imagen de entrada en escala de grises
        
        [File_Name, Path_Name] = uigetfile();
        img = imread([Path_Name, File_Name]);
        
        
        imagenEntrada = handles.imagenEntrada;      %el objeto que se va a manejar
        %img = imread('fogata.png');                 %leer la imagen y asignarla en una matriz
        imagenGris = rgb2gray(img);                  %convertir la imagen a escala de grises
        imagenGrisLogaritmo = imagenGris;           %imagen para transformación logarítmica
        imagenGrisPowerLaw = imagenGris;            %imagen para power law operación
        
        
        %----Diálogo de carga----------------------------------------------
        f = waitbar(0,'Please wait...');
        pause(.5)
        
        waitbar(.67,f,'Processing your data');
        pause(.5)
        close(f)
        %------------------------------------------------------------------
        imshow(imagenGris, 'Parent', imagenEntrada); %mostrar la imagen en escala de grises en el axes imagenEntrada
        
        %Activar las vistas de las etiquetas de imágenes de salida
        set(handles.linearTransformation,'Visible','on');
        set(handles.logarithmicTransformation,'Visible','on');
        set(handles.powerLawTransformation,'Visible','on');
  
        
        %---------------Linear Transformation------------------------------
        l = 256;    %el valor maximo en escala de grises que puede alcanzar la imagen
        
        for i = 1:size(imagenGris,1)
            for j = 1:size(imagenGris,2)
                r = imagenGris(i,j);    %obtener el valor de cada pixel de la imagen
                s = l - 1 - r;          %aplicar la operacion
                imagenGris(i,j) = s;    %asignar la salida a cada pixel de la imagen
            end
        end        
        imshow(imagenGris,'Parent',handles.salida1);    %mostrar la salida ya transformada
        
        
     
        %---------------Logarithmic Transformation-------------------------
        c = 50;     %constante de operacion
        
      
        for i = 1:size(imagenGrisLogaritmo,1)
            for j = 1:size(imagenGrisLogaritmo,2)
                r = imagenGrisLogaritmo(i,j);    %obtener el valor de cada pixel de la imagen
                s =  c * log(double(1+r));       %aplicar la operacion casteando a doble. Matlab no deja operar logaritmo con tipo uint8
                s = uint8(s);                   %castear a entero para evitar los decimales del resultado del logaritmo
                
                if s <= 255     %¿está dentro del rango?
                    imagenGrisLogaritmo(i,j) = s;    %asignar la salida a cada pixel de la imagen
                elseif s > 255  
                    imagenGrisLogaritmo(i,j) = 255;    %asignar la salida a cada pixel de la imagen
                end
            end
        end        
        imshow(imagenGrisLogaritmo,'Parent',handles.salida2);    %mostrar la salida ya transformada
        
        %---------------Powe Law Transformation----------------------------
        c1 = 0.001;     %constante de operacion
        gamma =  2.5;
        
      
        for i = 1:size(imagenGrisPowerLaw,1)
            for j = 1:size(imagenGrisPowerLaw,2)
                r = imagenGrisPowerLaw(i,j);    %obtener el valor de cada pixel de la imagen
                s =  c1 * power(double(r),gamma);    %aplicar la operacion
                s = uint8(s);                   %castear a entero para evitar los decimales del resultado del logaritmo
                
                if s <= 255     %¿está dentro del rango?
                    imagenGrisPowerLaw(i,j) = s;    %asignar la salida a cada pixel de la imagen
                elseif s > 255  
                    imagenGrisPowerLaw(i,j) = 255;    %asignar la salida a cada pixel de la imagen
                end
            end
        end        
        imshow(imagenGrisPowerLaw,'Parent',handles.salida3);    %mostrar la salida ya transformada


% --- Executes on button press in cargarImagenPT.
function cargarImagenPT_Callback(hObject, eventdata, handles)
    [File_Name, Path_Name] = uigetfile();
    img = imread([Path_Name, File_Name]);
    imagenEntrada = handles.imagenEntrada;      %el objeto que se va a manejar
    imagenGris = rgb2gray(img);                  %convertir la imagen a escala de grises
    imagenGrisContrastStretching = imagenGris;
    imagenGrisIntensitySlicing = imagenGris;
    
     %----Diálogo de carga----------------------------------------------
        f = waitbar(0,'Please wait...');
        pause(.5)
        
        waitbar(.67,f,'Processing your data');
        pause(.5)
        close(f)
        %------------------------------------------------------------------
        
        
    
    %---------ContrastStretching-----------------------------------------------
    
    r1 = 50;
    r2 = 100;
    s1 = 50;
    s2 = 200;
    
    
    for i = 1:size(imagenGrisContrastStretching,1)
        for j = 1:size(imagenGrisContrastStretching,2)
            r = imagenGrisContrastStretching(i,j);    %obtener el valor de cada pixel de la imagen
            if 0 <= r && r <= r1
                s = (s1/r1)*r;
               imagenGrisContrastStretching(i,j) = s;
            elseif r1 < r && r <= r2
                s = ((s2-s1)/(r2-r1))*(r-r1)+s1;
                imagenGrisContrastStretching(i,j) = s;
            elseif r2 < r && r <= 255
                s = ((255-s2)/(255-r2))*(r-r2)+s2;
                imagenGrisContrastStretching(i,j) = s;
            end        
        end
    end
    imshow(imagenGrisContrastStretching,'Parent',handles.salida1);    %mostrar la salida ya transformada
    
    
    %---------Intensity-Level Slicing-----------------------------------------------
    A = 15;
    B = 50;
    
    for i = 1:size(imagenGrisIntensitySlicing,1)
        for j = 1:size(imagenGrisIntensitySlicing,2)
            r = imagenGrisContrastStretching(i,j);    %obtener el valor de cada pixel de la imagen
            if A < r && r < B
                imagenGrisIntensitySlicing(i,j) = 255;
            else
                imagenGrisIntensitySlicing(i,j) = 0;   
            end
        end
    end
    imshow(imagenGrisIntensitySlicing,'Parent',handles.salida2);    %mostrar la salida ya transformada
    imshow(imagenGris, 'Parent', imagenEntrada); %mostrar la imagen en escala de grises en el axes imagenEntrada
        
    %Activar las vistas de las etiquetas de imágenes de salida
    set(handles.contrastStretching,'Visible','on');
    set(handles.intensityLevelSlicing,'Visible','on');


% --- Executes on button press in cargarImagenHist.
function cargarImagenHist_Callback(hObject, eventdata, handles)
    [File_Name, Path_Name] = uigetfile();
    img = imread([Path_Name, File_Name]);
    imagenEntrada = handles.imagenEntrada;      %el objeto que se va a manejar
    imagenGris = rgb2gray(img);                  %convertir la imagen a escala de grises
    
    escalaGris = 1:256;
    l = 256;
   
   
    
     %----Diálogo de carga----------------------------------------------
        f = waitbar(0,'Please wait...');
        pause(.5)
        
        waitbar(.67,f,'Processing your data');
        pause(.5)
        close(f)
     %------------------------------------------------------------------
    
    
    
    %para sacar la cantidad de ocurrencias de cada nivel de gris
    for i = 1:size(imagenGris,1)
        for j = 1:size(imagenGris,2)
            r = imagenGris(i,j);
            if r == 0
                r = 1;
                escalaGris(r) = escalaGris(r)+1;
            %else
             %   escalaGris(r) = escalaGris(r)+1;
            end
            escalaGris(r) = escalaGris(r)+1;
        end
    end
    
    totalPixeles = numel(imagenGris);
    
    cdf = 0;
    pdfArreglo = 1:256;
    cdfArreglo = 1:256;
    salidaNivelGris = 1:256;
    filas = 1:256;
    
    %para calcular el histograma
    for i = 1:256
        pdf = escalaGris(i)/totalPixeles;
        pdfArreglo(i) = pdf;
        cdf = cdf + pdf;
        cdfArreglo(i) = cdf;
        salidaNivelGris(i) = l * cdf;
        salidaNivelGris(i) = round(salidaNivelGris(i));
        if salidaNivelGris(i) > 255
            salidaNivelGris(i) = 255;
        end    
           % salida = sprintf('Input Level: %d | Output Level: %d', i, salidaNivelGris(i));
            %disp(salida)
        %else
            %salidaNivelGris(i);
            %salida = sprintf('Input Level: %d | Output Level: %d', i, salidaNivelGris(i));
            %disp(salida)
    end
    
      %para llenar la tabla
       datos = [filas',escalaGris',pdfArreglo',cdfArreglo',salidaNivelGris'];
       set(handles.tablaHistograma,'Data',datos);
       set(handles.tablaHistograma,'ColumnName',{'InputGrayLevel';'Ocurrence';'PDF';'CDF';'OutputGrayLevel'});
       set(handles.tablaHistograma,'Visible','on');
    
    imagenGris1 = imagenGris;
       
    %para ecualizar el histograma
     for i = 1:size(imagenGris1,1)
        for j = 1:size(imagenGris1,2)
            r = imagenGris1(i,j);
            for k = 1:256
                if r == k
                    imagenGris1(i,j) = salidaNivelGris(r);
                end                
            end
        end
     end
     
    %------------------Histogram Matching----------------------------------
    escalaGrisHM = 1:256;
    %para sacar la cantidad de ocurrencias de cada nivel de gris
    for i = 1:size(imagenGris1,1)
        for j = 1:size(imagenGris1,2)
            r = imagenGris1(i,j);
            if r == 0
                r = 1;
                escalaGrisHM(r) = escalaGris(r)+1;
            %else
             %   escalaGris(r) = escalaGris(r)+1;
            end
            escalaGrisHM(r) = escalaGris(r)+1;
        end
    end
    
    salidaNivelGris1 = 1:256;
    %para calcular el histograma nuevo
    for i = 1:256
        pdf = escalaGrisHM(i)/totalPixeles;
        cdf = cdf + pdf;
        salidaNivelGris1(i) = l * cdf;
        salidaNivelGris1(i) = round(salidaNivelGris1(i));
        if salidaNivelGris1(i) > 255
            salidaNivelGris1(i) = 255;
        end    
    end
    imagenGris2 = imagenGris1;
     %para ecualizar el histograma nuevo
     for i = 1:size(imagenGris2,1)
        for j = 1:size(imagenGris2,2)
            r = imagenGris2(i,j);
            for k = 1:256
                if r == k
                    imagenGris2(i,j) = salidaNivelGris(r);
                end                
            end
        end
     end
     
    imshow(imagenGris, 'Parent', imagenEntrada); %mostrar la imagen en escala de grises en el axes imagenEntrada
    imshow(imagenGris1,'Parent',handles.salida1);    %mostrar la salida ya ecualizada
    imshow(imagenGris2,'Parent',handles.salida3);    %mostrar la salida ya haciendo matching
    set(handles.histogram,'Visible','on');
    set(handles.histogramMatching,'Visible','on');
    
    
 
    
    
     
