import random
from reportlab.lib.pagesizes import A4
from reportlab.platypus import SimpleDocTemplate, Table, TableStyle, Paragraph, Spacer, PageBreak
from reportlab.lib import colors
from reportlab.lib.styles import getSampleStyleSheet, ParagraphStyle
from reportlab.lib.units import inch
from reportlab.graphics.shapes import Drawing, Line, Rect
from reportlab.graphics import renderPDF

# CONFIGURATION
MATRIX_SIZE = 5  # 5x5 matrix
FIXED_NUMBERS = list(range(15, 23))
NUMBER_POOL = set(range(1, 41))

# Step 1: Function to generate one bingo card
def generate_bingo_card():
    num_cells = MATRIX_SIZE * MATRIX_SIZE
    
    # Reserve one cell for the free space (center cell)
    card_numbers = FIXED_NUMBERS.copy()
    remaining_needed = num_cells - len(FIXED_NUMBERS) - 1  # -1 for free space
    remaining_pool = list(NUMBER_POOL - set(FIXED_NUMBERS))
    random.shuffle(remaining_pool)
    card_numbers.extend(remaining_pool[:remaining_needed])
    random.shuffle(card_numbers)
    
    # Create grid with numbers
    grid = []
    card_index = 0
    for i in range(MATRIX_SIZE):
        row = []
        for j in range(MATRIX_SIZE):
            if i == 2 and j == 2:  # Center cell (free space)
                row.append("ISSC\nAlumni")  # Free space text
            else:
                row.append(str(card_numbers[card_index]))
                card_index += 1
        grid.append(row)
    
    return grid

# Function to create photo placeholder
def create_photo_placeholder():
    # Create a simple bordered rectangle for photo
    photo_border = Table([['']], colWidths=3.25*inch, rowHeights=2.6*inch)
    photo_border.setStyle(TableStyle([
        ('GRID', (0,0), (-1,-1), 2, colors.black),
        ('VALIGN', (0,0), (-1,-1), 'MIDDLE'),
        ('ALIGN', (0,0), (-1,-1), 'CENTER'),
    ]))
    return photo_border

# Custom cut line class
class CutLine(Spacer):
    def __init__(self, width, height=0.1*inch):
        Spacer.__init__(self, width, height)
        self.width = width
        self.height = height
    
    def draw(self):
        canvas = self.canv
        # Draw a dashed line across the page width
        canvas.saveState()
        canvas.setDash([5, 3])  # 5 units on, 3 units off for dashed line
        canvas.setLineWidth(1)
        canvas.setStrokeColor(colors.grey)
        
        # Draw line with scissors symbols
        y_pos = self.height / 2
        
        # Left scissors symbol
        canvas.drawString(0.5*inch, y_pos - 3, "✂")
        
        # Dashed line
        canvas.line(0.8*inch, y_pos, A4[0] - 0.8*inch, y_pos)
        
        # Right scissors symbol  
        canvas.drawString(A4[0] - 0.7*inch, y_pos - 3, "✂")
        
        # "CUT HERE" text in the middle
        text_width = canvas.stringWidth("CUT HERE", "Helvetica", 8)
        canvas.setFont("Helvetica", 8)
        canvas.drawString((A4[0] - text_width) / 2, y_pos + 5, "CUT HERE")
        
        canvas.restoreState()

# Custom class for combined card layout (photo + bingo card)
class CombinedCardLayout:
    def __init__(self, bingo_grid):
        self.bingo_grid = bingo_grid
    
    def create_table(self):
        # Create the bingo table
        bingo_table = Table(self.bingo_grid, colWidths=52, rowHeights=42)
        bingo_table.setStyle(TableStyle([
            # Grid and basic formatting
            ('GRID', (0,0), (-1,-1), 1.5, colors.black),
            ('VALIGN', (0,0), (-1,-1), 'MIDDLE'),
            ('ALIGN', (0,0), (-1,-1), 'CENTER'),
            ('FONTNAME', (0,0), (-1,-1), 'Helvetica-Bold'),
            ('FONTSIZE', (0,0), (-1,-1), 12),
            
            # Special formatting for free space (center cell)
            ('BACKGROUND', (2,2), (2,2), colors.lightgrey),
            ('FONTSIZE', (2,2), (2,2), 8),
            ('FONTNAME', (2,2), (2,2), 'Helvetica-Bold'),
        ]))
        
        # Create photo placeholder
        photo_placeholder = create_photo_placeholder()
        
        # Combine photo and bingo card in a main table (2 columns: photo | bingo card)
        main_content = [[photo_placeholder, bingo_table]]
        
        main_table = Table(main_content, colWidths=[3.5*inch, 2.8*inch])
        main_table.setStyle(TableStyle([
            ('VALIGN', (0,0), (-1,-1), 'MIDDLE'),
            ('LEFTPADDING', (0,0), (-1,-1), 5),
            ('RIGHTPADDING', (0,0), (-1,-1), 5),
            ('TOPPADDING', (0,0), (-1,-1), 5),
            ('BOTTOMPADDING', (0,0), (-1,-1), 5),
        ]))
        
        return main_table

# Step 2: Build PDF with exactly 2 cards per page
def build_pdf(filename="bingo_cards_with_photo_2.pdf", num_cards=80):
    doc = SimpleDocTemplate(
        filename, 
        pagesize=A4, 
        topMargin=0.2*inch, 
        bottomMargin=0.2*inch,
        leftMargin=0.3*inch,
        rightMargin=0.3*inch
    )
    elements = []
    styles = getSampleStyleSheet()
    
    # Enhanced title style
    title_style = ParagraphStyle(
        'ISSC_Title',
        parent=styles['Heading1'],
        fontName='Helvetica-Bold',
        alignment=1,  # Center alignment
        fontSize=18,
        spaceAfter=5,
        spaceBefore=3,
        textColor=colors.black
    )
    
    # Name line style
    name_style = ParagraphStyle(
        'NameLine',
        parent=styles['Normal'],
        fontName='Helvetica-Bold',
        fontSize=10,
        spaceAfter=8,
        spaceBefore=5
    )
    
    card_count = 0
    while card_count < num_cards:
        # === FIRST CARD (TOP HALF) ===
        card1_grid = generate_bingo_card()
        card1_layout = CombinedCardLayout(card1_grid)
        
        # Add first card elements
        elements.append(Paragraph("ISSC BINGO GAME CARD", title_style))
        elements.append(card1_layout.create_table())
        elements.append(Paragraph("Name: _________________________________", name_style))
        
        # === CUT LINE ===
        elements.append(CutLine(A4[0]))
        elements.append(Spacer(1, 0.05*inch))
        
        # === SECOND CARD (BOTTOM HALF) ===
        if card_count + 1 < num_cards:  # Make sure we don't exceed the requested number
            card2_grid = generate_bingo_card()
            card2_layout = CombinedCardLayout(card2_grid)
            
            # Add second card elements
            elements.append(Paragraph("ISSC BINGO GAME CARD", title_style))
            elements.append(card2_layout.create_table())
            elements.append(Paragraph("Name: _________________________________", name_style))
            
            card_count += 2
        else:
            card_count += 1
        
        # Add page break if there are more cards to generate
        if card_count < num_cards:
            elements.append(PageBreak())
    
    doc.build(elements)
    print(f"Generated {num_cards} bingo cards with photo placeholder in {filename}")
    print(f"Total pages: {(num_cards + 1) // 2}")
    print("Each card now includes:")
    print("- Photo rectangle placeholder (left side)")
    print("- 5x5 Bingo grid (right side)")
    print("- Name field")
    print("- Cut lines between cards")

if __name__ == "__main__":
    build_pdf()